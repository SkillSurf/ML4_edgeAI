/**
  ******************************************************************************
  * @file    sinewave_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2024-08-12T01:05:54-0700
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "sinewave_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_sinewave_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_sinewave_weights_array_u64[161] = {
  0xbe8eaee7beaaf656U, 0xbe5c6fe03eee0e09U, 0x3e4f412a3eaa1278U, 0x3f2952d0bf14d446U,
  0x3e118b2dbeec31bdU, 0xbe6e59f2bef6aaa8U, 0xbdfb4008bf11592bU, 0xbe2282043f11bca2U,
  0x0U, 0xbf948d58U, 0xbeb64e16bef20326U, 0x3da28f9700000000U,
  0xbc3b474600000000U, 0x0U, 0x0U, 0xbddb0027U,
  0xbd6e39b8be022182U, 0x3d4c27003eafe4a6U, 0x3cc664473f0352d0U, 0xbebf2687bc8cfe70U,
  0x3e5f6a3fbe869d8fU, 0xbecbd440be9ab582U, 0xbe888f5c3eb4e8dbU, 0xbed6ebe13e8dfd73U,
  0x3e8b1645bed9df30U, 0x3d1326403e923470U, 0xbeab0f37bdf0b988U, 0xbebb5c23bd46b250U,
  0xbe76d21ebe6535afU, 0x3dcb6b5c3e5395daU, 0xbec349bd3e74dfcaU, 0xbe6f91823e4fb2a2U,
  0xbcaf1be0bed55227U, 0x3eaa8ab5bd6ba888U, 0xbeda54edbe9cf81eU, 0xbec7192b3ec8dce9U,
  0x3d4145e03e720096U, 0xbdeed2783c1d35e0U, 0x3e22ca92be3d9c35U, 0x3e9486ff3ec62f45U,
  0x3e0ff9723e73639aU, 0x3e3f44c63cf14355U, 0x3e641b68beb9a33fU, 0x3ef207dcbeb7ede5U,
  0xbe817753becaa09fU, 0x3dc0e62cbdfb42e8U, 0xbc9f36d0be6e0524U, 0xbe94e3babca7f28cU,
  0xbe0194883ec95069U, 0xbdf060bcbec3acebU, 0xbdb8d7eb3e92cee5U, 0x3d4c49c33eb50fd9U,
  0x3ed9c112bd5a6dd8U, 0xbbff1f403df80c1cU, 0xbdc35818be1d907cU, 0x3eac743f3edc1b42U,
  0xbe209d963d886500U, 0xbdab4cecbedaa00eU, 0xbe8d48a83e82f16fU, 0xbeb65842be10744aU,
  0xbe85a923becd1f27U, 0x3da01a043e8e3ab3U, 0x3e96bda53eb119d7U, 0x39d62000be85df90U,
  0x3d486110beca6e03U, 0xbeab47503e38f866U, 0x3d861a3ebd1a24adU, 0x3cd3ee663e96e157U,
  0xbe1faf933ed6a681U, 0xbe5ee7103ebe0f33U, 0x3c4a62603ec4d7c5U, 0x3e3405063eafb7cfU,
  0x3d6033303e164ac6U, 0x3dac31e43d73024eU, 0xbecace663e04899bU, 0x3e9571afbe974e15U,
  0x3e9194b63e8ba6efU, 0x3e801933be5851b2U, 0xbe5ffa533ed03179U, 0xbe390548be4e0d4dU,
  0xbde01664bda9a8ccU, 0x3dd86c9cbe235d30U, 0x3ed76c4f3df9f640U, 0x3e2dfb343e4f0396U,
  0x3ea9e07b3e32c49aU, 0xbca79260be93ee8cU, 0x3e9e6e913ebebb79U, 0x3e470bbe3eb52f2fU,
  0x3ecc39abbe6a4966U, 0x3d9440ccbe9874a6U, 0xbe2abd03bdb88bb3U, 0x3e494d96bda02690U,
  0x3e546eaebe8f0544U, 0x3ccc9ce0be70969eU, 0x3eb31e733e8c177dU, 0xbd515b303ecfce87U,
  0x3d6ec140be3e0992U, 0xbea231933e517877U, 0xbea72de53d4a527aU, 0x3e7307703ea7bd61U,
  0xbeed1c523dcae9e4U, 0xbdf12a14be97d810U, 0x3db6ae843eb7ce3fU, 0xbeb9fd933d495b43U,
  0xbebfa1b0be64d1a2U, 0x3e469296be8d33eaU, 0xbed167533e7bd246U, 0xbe4edd3cbe311a8aU,
  0xbe884ca63eb11b1fU, 0x3e2c4acebec46dcaU, 0xbedc1af4be4a145aU, 0xbc7b00003cd3f430U,
  0xbdf2d3b0bdbcd29cU, 0x3ea94ab73f2be48eU, 0xbe02f044be0ab228U, 0x3d8bbc35bec04375U,
  0xbdcd0b5ebdd6b720U, 0xbe6b27603dc6c754U, 0x3e1c1f563da8aee4U, 0xbda40ee0bd8e52bcU,
  0x3da1a984be9221dcU, 0x3ea8331bbed43eb3U, 0xbd367d453dd9f678U, 0x3eaa69eb3e175d02U,
  0xbebc46793d4c57f0U, 0x3db46584bd8cf8bcU, 0x3e4b8beabd2e25b0U, 0xbe7bfd573ee5cfcfU,
  0xbd410b503e498492U, 0xbe079ff6bf6ae551U, 0xbfa70bfcbf759a53U, 0x3efd1f3abd908eacU,
  0x3e75983dbda8ae30U, 0xbe5889c5be4ff5cdU, 0xbe88c546be064b5eU, 0xbdc9aea43e16de9eU,
  0xbdadaa483e70f64aU, 0xbeda7240be127f9fU, 0xbe755b553ee1f306U, 0x3e604cd03e1750f6U,
  0xbe284d833e9acb51U, 0xbda4f9c8be516452U, 0xbe93341c3e6dcf96U, 0x3b38e5803e27af83U,
  0xbba241b5bf24b0c8U, 0xbda0b53b00000000U, 0xbe545cdaU, 0xbd922997bde48494U,
  0xbe84f4c9bdaceb29U, 0xbcf010dfU, 0xbe80b54abf0558aaU, 0xbe0fc6a03e91f718U,
  0xbe1e55513fca8c97U, 0x3eff1ec43f159aeeU, 0x3e1bf62cbecfa342U, 0x3e3e7a10bf1987e7U,
  0xbe43516d3e80e2c0U, 0x3e5dc9883edeaa00U, 0xbe7c24f33fd41878U, 0xbe53253a3fc6520bU,
  0xbedb60abU,
};


ai_handle g_sinewave_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_sinewave_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

