#include "bc7enc_c.h"
#include "bc7enc.h"

#ifdef __cplusplus
extern "C" {
#endif

    void bc7enc_compress_block_init_c(void)
    {
        bc7enc_compress_block_init();
    }

    void bc7enc_compress_block_params_init_c(
        bc7enc_compress_block_params* p)
    {
        bc7enc_compress_block_params_init(p);
    }

    void bc7enc_compress_block_params_init_linear_weights_c(struct bc7enc_compress_block_params* p)
    {
        bc7enc_compress_block_params_init_linear_weights(p);
    }

    void bc7enc_compress_block_params_init_perceptual_weights_c(struct bc7enc_compress_block_params* p)
    {
        bc7enc_compress_block_params_init_perceptual_weights(p);
    }

    int bc7enc_compress_block_c(
        void* block,
        const void* pixels_rgba,
        const bc7enc_compress_block_params* params)
    {
        return bc7enc_compress_block(block, pixels_rgba, params);
    }

#ifdef __cplusplus
}
#endif
