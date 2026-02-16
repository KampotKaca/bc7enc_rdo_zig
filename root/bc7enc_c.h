#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
    struct bc7enc_compress_block_params;

    void bc7enc_compress_block_init_c(void);
    void bc7enc_compress_block_params_init_linear_weights_c(struct bc7enc_compress_block_params* p);
    void bc7enc_compress_block_params_init_perceptual_weights_c(struct bc7enc_compress_block_params* p);

    void bc7enc_compress_block_params_init_c(struct bc7enc_compress_block_params* p);

    int bc7enc_compress_block_c(
        void* block,
        const void* pixels_rgba,
        const struct bc7enc_compress_block_params* params);

#ifdef __cplusplus
}
#endif
