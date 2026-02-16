const std = @import("std");

const c = @cImport({
    @cInclude("rdo_bc.h");
});

pub const init = c.bc_rdo_init;
pub const encode = c.bc_rdo_encode;
pub const is_ok = c.is_ok;
