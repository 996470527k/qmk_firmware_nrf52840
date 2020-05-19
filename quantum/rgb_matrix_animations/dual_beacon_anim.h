#ifndef DISABLE_RGB_MATRIX_DUAL_BEACON
RGB_MATRIX_EFFECT(DUAL_BEACON)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static void DUAL_BEACON_math(HSV* hsv, int8_t sin, int8_t cos, uint8_t i, uint8_t time) {
    hsv->h = ((g_led_config.point[i].y - k_rgb_matrix_center.y) * cos + (g_led_config.point[i].x - k_rgb_matrix_center.x) * sin) / 128 + rgb_matrix_config.hue;
}

bool DUAL_BEACON(effect_params_t* params, rgb_config_t* config) {
    return effect_runner_sin_cos_i(params, config, &DUAL_BEACON_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif // DISABLE_RGB_MATRIX_DUAL_BEACON
