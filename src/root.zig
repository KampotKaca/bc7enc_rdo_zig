const std = @import("std");

const c = @cImport({
    @cInclude("rdo_bc.h");
});

///This must be called from main thread first until you touch any encoder.
pub const initbc7enc = c.init_bc7enc;
pub const initEncoder = c.bc_rdo_init;
pub const deinitEncoder = c.bc_rdo_deinit;
pub const encode = c.bc_rdo_encode;
pub const is_ok = c.is_ok;
