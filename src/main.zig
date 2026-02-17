const bc = @import("bc");

pub fn main() !void {
    const encoder = bc.initEncoder(null, null);
    defer bc.deinitEncoder(encoder);
}
