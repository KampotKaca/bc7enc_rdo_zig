#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

    enum OUTPUT_FORMAT
    {
        OUTPUT_FORMAT_UNKNOWN = 0,
        OUTPUT_FORMAT_R32G32B32A32_TYPELESS = 1,
        OUTPUT_FORMAT_R32G32B32A32_FLOAT = 2,
        OUTPUT_FORMAT_R32G32B32A32_UINT = 3,
        OUTPUT_FORMAT_R32G32B32A32_SINT = 4,
        OUTPUT_FORMAT_R32G32B32_TYPELESS = 5,
        OUTPUT_FORMAT_R32G32B32_FLOAT = 6,
        OUTPUT_FORMAT_R32G32B32_UINT = 7,
        OUTPUT_FORMAT_R32G32B32_SINT = 8,
        OUTPUT_FORMAT_R16G16B16A16_TYPELESS = 9,
        OUTPUT_FORMAT_R16G16B16A16_FLOAT = 10,
        OUTPUT_FORMAT_R16G16B16A16_UNORM = 11,
        OUTPUT_FORMAT_R16G16B16A16_UINT = 12,
        OUTPUT_FORMAT_R16G16B16A16_SNORM = 13,
        OUTPUT_FORMAT_R16G16B16A16_SINT = 14,
        OUTPUT_FORMAT_R32G32_TYPELESS = 15,
        OUTPUT_FORMAT_R32G32_FLOAT = 16,
        OUTPUT_FORMAT_R32G32_UINT = 17,
        OUTPUT_FORMAT_R32G32_SINT = 18,
        OUTPUT_FORMAT_R32G8X24_TYPELESS = 19,
        OUTPUT_FORMAT_D32_FLOAT_S8X24_UINT = 20,
        OUTPUT_FORMAT_R32_FLOAT_X8X24_TYPELESS = 21,
        OUTPUT_FORMAT_X32_TYPELESS_G8X24_UINT = 22,
        OUTPUT_FORMAT_R10G10B10A2_TYPELESS = 23,
        OUTPUT_FORMAT_R10G10B10A2_UNORM = 24,
        OUTPUT_FORMAT_R10G10B10A2_UINT = 25,
        OUTPUT_FORMAT_R11G11B10_FLOAT = 26,
        OUTPUT_FORMAT_R8G8B8A8_TYPELESS = 27,
        OUTPUT_FORMAT_R8G8B8A8_UNORM = 28,
        OUTPUT_FORMAT_R8G8B8A8_UNORM_SRGB = 29,
        OUTPUT_FORMAT_R8G8B8A8_UINT = 30,
        OUTPUT_FORMAT_R8G8B8A8_SNORM = 31,
        OUTPUT_FORMAT_R8G8B8A8_SINT = 32,
        OUTPUT_FORMAT_R16G16_TYPELESS = 33,
        OUTPUT_FORMAT_R16G16_FLOAT = 34,
        OUTPUT_FORMAT_R16G16_UNORM = 35,
        OUTPUT_FORMAT_R16G16_UINT = 36,
        OUTPUT_FORMAT_R16G16_SNORM = 37,
        OUTPUT_FORMAT_R16G16_SINT = 38,
        OUTPUT_FORMAT_R32_TYPELESS = 39,
        OUTPUT_FORMAT_D32_FLOAT = 40,
        OUTPUT_FORMAT_R32_FLOAT = 41,
        OUTPUT_FORMAT_R32_UINT = 42,
        OUTPUT_FORMAT_R32_SINT = 43,
        OUTPUT_FORMAT_R24G8_TYPELESS = 44,
        OUTPUT_FORMAT_D24_UNORM_S8_UINT = 45,
        OUTPUT_FORMAT_R24_UNORM_X8_TYPELESS = 46,
        OUTPUT_FORMAT_X24_TYPELESS_G8_UINT = 47,
        OUTPUT_FORMAT_R8G8_TYPELESS = 48,
        OUTPUT_FORMAT_R8G8_UNORM = 49,
        OUTPUT_FORMAT_R8G8_UINT = 50,
        OUTPUT_FORMAT_R8G8_SNORM = 51,
        OUTPUT_FORMAT_R8G8_SINT = 52,
        OUTPUT_FORMAT_R16_TYPELESS = 53,
        OUTPUT_FORMAT_R16_FLOAT = 54,
        OUTPUT_FORMAT_D16_UNORM = 55,
        OUTPUT_FORMAT_R16_UNORM = 56,
        OUTPUT_FORMAT_R16_UINT = 57,
        OUTPUT_FORMAT_R16_SNORM = 58,
        OUTPUT_FORMAT_R16_SINT = 59,
        OUTPUT_FORMAT_R8_TYPELESS = 60,
        OUTPUT_FORMAT_R8_UNORM = 61,
        OUTPUT_FORMAT_R8_UINT = 62,
        OUTPUT_FORMAT_R8_SNORM = 63,
        OUTPUT_FORMAT_R8_SINT = 64,
        OUTPUT_FORMAT_A8_UNORM = 65,
        OUTPUT_FORMAT_R1_UNORM = 66,
        OUTPUT_FORMAT_R9G9B9E5_SHAREDEXP = 67,
        OUTPUT_FORMAT_R8G8_B8G8_UNORM = 68,
        OUTPUT_FORMAT_G8R8_G8B8_UNORM = 69,
        OUTPUT_FORMAT_BC1_TYPELESS = 70,
        OUTPUT_FORMAT_BC1_UNORM = 71,
        OUTPUT_FORMAT_BC1_UNORM_SRGB = 72,
        OUTPUT_FORMAT_BC2_TYPELESS = 73,
        OUTPUT_FORMAT_BC2_UNORM = 74,
        OUTPUT_FORMAT_BC2_UNORM_SRGB = 75,
        OUTPUT_FORMAT_BC3_TYPELESS = 76,
        OUTPUT_FORMAT_BC3_UNORM = 77,
        OUTPUT_FORMAT_BC3_UNORM_SRGB = 78,
        OUTPUT_FORMAT_BC4_TYPELESS = 79,
        OUTPUT_FORMAT_BC4_UNORM = 80,
        OUTPUT_FORMAT_BC4_SNORM = 81,
        OUTPUT_FORMAT_BC5_TYPELESS = 82,
        OUTPUT_FORMAT_BC5_UNORM = 83,
        OUTPUT_FORMAT_BC5_SNORM = 84,
        OUTPUT_FORMAT_B5G6R5_UNORM = 85,
        OUTPUT_FORMAT_B5G5R5A1_UNORM = 86,
        OUTPUT_FORMAT_B8G8R8A8_UNORM = 87,
        OUTPUT_FORMAT_B8G8R8X8_UNORM = 88,
        OUTPUT_FORMAT_R10G10B10_XR_BIAS_A2_UNORM = 89,
        OUTPUT_FORMAT_B8G8R8A8_TYPELESS = 90,
        OUTPUT_FORMAT_B8G8R8A8_UNORM_SRGB = 91,
        OUTPUT_FORMAT_B8G8R8X8_TYPELESS = 92,
        OUTPUT_FORMAT_B8G8R8X8_UNORM_SRGB = 93,
        OUTPUT_FORMAT_BC6H_TYPELESS = 94,
        OUTPUT_FORMAT_BC6H_UF16 = 95,
        OUTPUT_FORMAT_BC6H_SF16 = 96,
        OUTPUT_FORMAT_BC7_TYPELESS = 97,
        OUTPUT_FORMAT_BC7_UNORM = 98,
        OUTPUT_FORMAT_BC7_UNORM_SRGB = 99,
        OUTPUT_FORMAT_AYUV = 100,
        OUTPUT_FORMAT_Y410 = 101,
        OUTPUT_FORMAT_Y416 = 102,
        OUTPUT_FORMAT_NV12 = 103,
        OUTPUT_FORMAT_P010 = 104,
        OUTPUT_FORMAT_P016 = 105,
        OUTPUT_FORMAT_420_OPAQUE = 106,
        OUTPUT_FORMAT_YUY2 = 107,
        OUTPUT_FORMAT_Y210 = 108,
        OUTPUT_FORMAT_Y216 = 109,
        OUTPUT_FORMAT_NV11 = 110,
        OUTPUT_FORMAT_AI44 = 111,
        OUTPUT_FORMAT_IA44 = 112,
        OUTPUT_FORMAT_P8 = 113,
        OUTPUT_FORMAT_A8P8 = 114,
        OUTPUT_FORMAT_B4G4R4A4_UNORM = 115,
        OUTPUT_FORMAT_P208 = 130,
        OUTPUT_FORMAT_V208 = 131,
        OUTPUT_FORMAT_V408 = 132,
        OUTPUT_FORMAT_FORCE_UINT = 0xffffffff
    };

	enum BC4_MODE_MASK
	{
	    BC4_MODE_MASK_MODE8_FLAG = 1,
	    BC4_MODE_MASK_MODE6_FLAG = 2,
	    BC4_MODE_MASK_ALL_MODES = 3,
	};

    enum BC1_APPROX_MODE
	{
		// The default mode. No rounding for 4-color colors 2,3. My older tools/compressors use this mode.
		// This matches the D3D10 docs on BC1.
		BC1_APPROX_MODE_CBC1IDEAL = 0,

		// NVidia GPU mode.
		BC1_APPROX_MODE_CBC1NVIDIA = 1,

		// AMD GPU mode.
		BC1_APPROX_MODE_CBC1AMD = 2,

		// This mode matches AMD Compressonator's output. It rounds 4-color colors 2,3 (not 3-color color 2).
		// This matches the D3D9 docs on DXT1.
		BC1_APPROX_MODE_CBC1IDEALROUND4 = 3
	};

    typedef struct {
        void* encoder;
        bool perceptual;
    }bc_rdo_encoder;

    typedef struct {
        int bc7_uber_level;
		int bc7enc_max_partitions_to_scan;
		bool perceptual;
		bool y_flip;
		uint32_t bc45_channel0;
		uint32_t bc45_channel1;

		enum BC1_APPROX_MODE bc1_mode;
		bool use_bc1_3color_mode;

		bool use_bc1_3color_mode_for_black;

		int bc1_quality_level;

		enum OUTPUT_FORMAT dxgi_format;

		float rdo_lambda;
		bool rdo_debug_output;
		float rdo_smooth_block_error_scale;
		bool custom_rdo_smooth_block_error_scale;
		uint32_t lookback_window_size;
		bool custom_lookback_window_size;
		bool bc7enc_rdo_bc7_quant_mode6_endpoints;
		bool bc7enc_rdo_bc7_weight_modes;
		bool bc7enc_rdo_bc7_weight_low_frequency_partitions;
		bool bc7enc_rdo_bc7_pbit1_weighting;
		float rdo_max_smooth_block_std_dev;
		bool rdo_allow_relative_movement;
		bool rdo_try_2_matches;
		bool rdo_ultrasmooth_block_handling;

		bool use_hq_bc345;
		int bc345_search_rad;
		uint32_t bc345_mode_mask;

		bool bc7enc_mode6_only;
		bool rdo_multithreading;

		bool bc7enc_reduce_entropy;
		uint32_t rdo_max_threads;
    }bc_rdo_init_options;

    typedef struct{
        uint16_t width;
        uint16_t height;

        uint8_t* image;
    }bc_rdo_init_info;

    typedef bool (*WriteFn)(void* user, const void* data, uint64_t size);

    void init_bc7enc();
    bc_rdo_encoder bc_rdo_init(const bc_rdo_init_info* info, const bc_rdo_init_options* options);
    void bc_rdo_deinit(bc_rdo_encoder encoder);
    bool bc_rdo_encode(bc_rdo_encoder encoder, bool force_dx10dds, void* user, WriteFn writeFn);

    inline bool is_ok(bc_rdo_encoder encoder) {
        return encoder.encoder != 0;
    }
    inline bc_rdo_init_options bc_rdo_get_default_options() {
        bc_rdo_init_options options = {};
        options.bc7_uber_level = 6;
		options.bc7enc_max_partitions_to_scan = 64;
		options.perceptual = false;
		options.y_flip = false;
		options.bc45_channel0 = 0;
		options.bc45_channel1 = 1;

		options.bc1_mode = BC1_APPROX_MODE_CBC1IDEAL;
		options.use_bc1_3color_mode = true;

		// We're just turning this on by default now; like NVDXT.EXE used to do back in the old original Xbox days.
		options.use_bc1_3color_mode_for_black = true; // false;

		options.bc1_quality_level = 18;

		options.dxgi_format = OUTPUT_FORMAT_BC7_UNORM;

		options.rdo_lambda = 0.0f;
		options.rdo_debug_output = false;
		options.rdo_smooth_block_error_scale = 15.0f;
		options.custom_rdo_smooth_block_error_scale = false;
		options.lookback_window_size = 128;
		options.custom_lookback_window_size = false;
		options.bc7enc_rdo_bc7_quant_mode6_endpoints = true;
		options.bc7enc_rdo_bc7_weight_modes = true;
		options.bc7enc_rdo_bc7_weight_low_frequency_partitions = true;
		options.bc7enc_rdo_bc7_pbit1_weighting = true;
		options.rdo_max_smooth_block_std_dev = 18.0f;
		options.rdo_allow_relative_movement = false;
		options.rdo_try_2_matches = true;
		options.rdo_ultrasmooth_block_handling = true;

		options.use_hq_bc345 = true;
		options.bc345_search_rad = 5;
		options.bc345_mode_mask = BC4_MODE_MASK_ALL_MODES;

		options.bc7enc_mode6_only = false;
		options.rdo_multithreading = true;

		options.bc7enc_reduce_entropy = false;
		options.rdo_max_threads = 128;

        return options;
    }

#ifdef __cplusplus
}
#endif
