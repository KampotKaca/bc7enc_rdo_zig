#include "rdo_bc.h"
#include "dds_defs.h"
#include "stdint.h"

#include "rdo_bc_encoder.h"
#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif


    void init_bc7enc() {
        bc7enc_compress_block_init();
    }

    bc_rdo_encoder bc_rdo_init(const bc_rdo_init_info* info, const bc_rdo_init_options* options) {
        utils::image_u8 image;
        image.init(info->width, info->height);

        memcpy(&image.get_pixels()[0], &info->image[0], info->width * info->height * sizeof(uint32_t));

        auto parameters = rdo_bc::rdo_bc_params();
        if(options != NULL) {
            parameters.m_bc7_uber_level = options->bc7_uber_level;
            parameters.m_bc7enc_max_partitions_to_scan = options->bc7enc_max_partitions_to_scan;
            parameters.m_perceptual = options->perceptual;
            parameters.m_y_flip = options->y_flip;
            parameters.m_bc45_channel0 = options->bc45_channel0;
            parameters.m_bc45_channel1 = options->bc45_channel1;

            parameters.m_bc1_mode = (rgbcx::bc1_approx_mode)options->bc1_mode;
            parameters.m_use_bc1_3color_mode = options->use_bc1_3color_mode;

            parameters.m_use_bc1_3color_mode_for_black = options->use_bc1_3color_mode_for_black;

            parameters.m_bc1_quality_level = options->bc1_quality_level;

            parameters.m_dxgi_format = (DXGI_FORMAT)options->dxgi_format;

            parameters.m_rdo_lambda = options->rdo_lambda;
            parameters.m_rdo_debug_output = options->rdo_debug_output;
            parameters.m_rdo_smooth_block_error_scale = options->rdo_smooth_block_error_scale;
            parameters.m_custom_rdo_smooth_block_error_scale = options->custom_rdo_smooth_block_error_scale;
            parameters.m_lookback_window_size = options->lookback_window_size;
            parameters.m_custom_lookback_window_size = options->custom_lookback_window_size;
            parameters.m_bc7enc_rdo_bc7_quant_mode6_endpoints = options->bc7enc_rdo_bc7_quant_mode6_endpoints;
            parameters.m_bc7enc_rdo_bc7_weight_modes = options->bc7enc_rdo_bc7_weight_modes;
            parameters.m_bc7enc_rdo_bc7_weight_low_frequency_partitions = options->bc7enc_rdo_bc7_weight_low_frequency_partitions;
            parameters.m_bc7enc_rdo_bc7_pbit1_weighting = options->bc7enc_rdo_bc7_pbit1_weighting;
            parameters.m_rdo_max_smooth_block_std_dev = options->rdo_max_smooth_block_std_dev;
            parameters.m_rdo_allow_relative_movement = options->rdo_allow_relative_movement;
            parameters.m_rdo_try_2_matches = options->rdo_try_2_matches;
            parameters.m_rdo_ultrasmooth_block_handling = options->rdo_ultrasmooth_block_handling;

            parameters.m_use_hq_bc345 = options->use_hq_bc345;
            parameters.m_bc345_search_rad = options->bc345_search_rad;
            parameters.m_bc345_mode_mask = options->bc345_mode_mask;

            parameters.m_bc7enc_mode6_only = options->bc7enc_mode6_only;
            parameters.m_rdo_multithreading = options->rdo_multithreading;

            parameters.m_bc7enc_reduce_entropy = options->bc7enc_reduce_entropy;

            parameters.m_rdo_max_threads = options->rdo_max_threads;
        }

        auto encoder = new rdo_bc::rdo_bc_encoder();
        if(!encoder->init(image, parameters)) {
            return { .encoder = nullptr };
        }

        return { .encoder = encoder, };
    }

    void bc_rdo_deinit(bc_rdo_encoder encoder) {
        delete (rdo_bc::rdo_bc_encoder*)encoder.encoder;
    }

    bool bc_rdo_encode(bc_rdo_encoder encoder) {
        auto enc = (rdo_bc::rdo_bc_encoder*)encoder.encoder;

        if(!enc->encode()) {
            return false;
        }
        return true;
    }

#ifdef __cplusplus
}
#endif
