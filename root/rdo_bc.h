#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        void* encoder;
    }bc_rdo_encoder;

    typedef struct {
        uint16_t width;
        uint16_t height;

        uint8_t* image;
        uint8_t* mem_for_encoder;

    }bc_rdo_init_options;

    bc_rdo_encoder bc_rdo_init(const bc_rdo_init_options* options);
    bool bc_rdo_encode(bc_rdo_encoder encoder);

    inline bool is_ok(bc_rdo_encoder encoder) {
        return encoder.encoder != 0;
    }

    uint64_t bc_rdo_get_encoder_size();

#ifdef __cplusplus
}
#endif
