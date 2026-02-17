const std = @import("std");
const bc = @import("bc");

pub fn main() !void {
    const encoder = bc.initEncoder(null, null);
    var writer: std.Io.Writer = .{
        .vtable = undefined,
        .buffer = undefined,
    };

    _ = bc.encode(encoder, false, &writer);
    defer bc.deinitEncoder(encoder);
}
