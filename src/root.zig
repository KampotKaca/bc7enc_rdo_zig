const std = @import("std");

const c = @cImport({
    @cInclude("bc7enc_c.h");
});

pub const init = c.bc7enc_compress_block_init_c;
pub const compressBlock = c.bc7enc_compress_block_c;
pub const compressBlockParamsInit = c.bc7enc_compress_block_params_init_c;
pub const compressBlockParamsInitLinearWeights = c.bc7enc_compress_block_params_init_linear_weights_c;
pub const compressBlockParamsInitPerceptualWeights = c.bc7enc_compress_block_params_init_perceptual_weights_c;
