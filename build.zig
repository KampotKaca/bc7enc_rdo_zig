const std = @import("std");
const builtin = @import("builtin");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const module = b.addModule("root", .{
        .root_source_file = b.path("src/root.zig"),
        .target = target,
        .optimize = optimize,
    });

    if (optimize == .Debug) {
        module.sanitize_c = .full;
        module.addCMacro("_DEBUG", "1");
    } else {
        module.sanitize_c = .off;
    }

    module.link_libcpp = true;

    // const ispc_step = b.addSystemCommand(&.{
    //     "ispc",
    //     "bc7e.ispc",
    //     "-O2",
    //     "--target=sse2,sse4,avx,avx2",
    //     "--opt=fast-math",
    //     "--opt=disable-assertions",
    //     "-o",
    //     "bc7e.o",
    //     "-h",
    //     "bc7e_ispc.h",
    // });

    // module.addCMacro("SUPPORT_BC7E", "1");
    module.addIncludePath(b.path("root"));
    module.addCSourceFiles(.{
        .files = &.{
            "root/rdo_bc.cpp",
            "root/bc7enc.cpp",
            "root/bc7decomp.cpp",
            "root/bc7decomp_ref.cpp",
            "root/lodepng.cpp",
            // "root/test.cpp",
            "root/rgbcx.cpp",
            "root/utils.cpp",
            "root/ert.cpp",
            "root/rdo_bc_encoder.cpp",
        },
        .language = .cpp,
        .flags = &.{"-std=c++20"},
    });
    // module.addObjectFile(b.path("bc7e.o"));
    // module.addObjectFile(b.path("bc7e_sse2.o"));
    // module.addObjectFile(b.path("bc7e_sse4.o"));
    // module.addObjectFile(b.path("bc7e_avx.o"));
    // module.addObjectFile(b.path("bc7e_avx2.o"));

    const exe = b.addExecutable(.{
        .name = "bc7enc_rdo_zig",
        .root_module = b.createModule(.{
            .root_source_file = b.path("src/main.zig"),
            .target = target,
            .optimize = optimize,
            .imports = &.{
                .{ .name = "bc", .module = module },
            },
        }),
    });

    // exe.step.dependOn(&ispc_step.step);

    b.installArtifact(exe);
    const run_step = b.step("run", "Run the app");

    const run_cmd = b.addRunArtifact(exe);
    run_step.dependOn(&run_cmd.step);

    run_cmd.step.dependOn(b.getInstallStep());

    if (b.args) |args| {
        run_cmd.addArgs(args);
    }
}
