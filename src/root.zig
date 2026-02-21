const std = @import("std");

const c = @cImport({
    @cInclude("rdo_bc.h");
});

///This must be called from main thread first until you touch any encoder.
pub const initbc7enc = c.init_bc7enc;
pub const initEncoder = c.bc_rdo_init;
pub const deinitEncoder = c.bc_rdo_deinit;
pub const getDefaultOptions = c.bc_rdo_get_default_options;
pub const is_ok = c.is_ok;

pub fn encode(encoder: c.bc_rdo_encoder, force_dx10dds: bool, writer: *std.Io.Writer) !usize {
    var data: WriterData = .{
        .writer = writer,
    };
    if (!c.bc_rdo_encode(encoder, force_dx10dds, &data, writeToWriter)) return error.failed_to_encode;

    return data.outputSize;
}

fn writeToWriter(
    user: ?*anyopaque,
    data: ?*const anyopaque,
    size: u64,
) callconv(.c) bool {
    const writer: *WriterData = @ptrCast(@alignCast(user));
    const bytes: [*]const u8 = @ptrCast(data);
    const slice = bytes[0..@intCast(size)];

    writer.outputSize += writer.writer.write(slice) catch {
        return false;
    };

    return true;
}

const WriterData = struct {
    writer: *std.Io.Writer,
    outputSize: usize = 0,
};
