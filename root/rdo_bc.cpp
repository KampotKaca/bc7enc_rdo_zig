#include "rdo_bc.h"
#include "stdint.h"

#include "rdo_bc_encoder.h"
#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif

    bc_rdo_encoder bc_rdo_init(const bc_rdo_init_options* options) {

        utils::image_u8 image;
        image.init(options->width, options->height);

        memcpy(&image.get_pixels()[0], &options->image[0], options->width * options->height * sizeof(uint32_t));

        rdo_bc::rdo_bc_params parameters = {};

        rdo_bc::rdo_bc_encoder* encoder = (rdo_bc::rdo_bc_encoder*)options->mem_for_encoder;
        if(!encoder->init(image, parameters)) {

        }

        return { .encoder = encoder, };
    }

    bool bc_rdo_encode(bc_rdo_encoder encoder) {
        return true;
    }

    uint64_t bc_rdo_get_encoder_size() {
        return sizeof(rdo_bc::rdo_bc_encoder);
    }

#ifdef __cplusplus
}
#endif
