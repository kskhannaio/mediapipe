// Copyright 2020 The MediaPipe Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MEDIAPIPE_CALCULATORS_TENSOR_IMAGE_TO_TENSOR_CONVERTER_H_
#define MEDIAPIPE_CALCULATORS_TENSOR_IMAGE_TO_TENSOR_CONVERTER_H_

#include "mediapipe/calculators/tensor/image_to_tensor_utils.h"
#include "mediapipe/framework/formats/tensor.h"
#include "mediapipe/framework/packet.h"
#include "mediapipe/framework/port/statusor.h"

namespace mediapipe {

struct Size {
  int width;
  int height;
};

// Converts image to tensor.
class ImageToTensorConverter {
 public:
  virtual ~ImageToTensorConverter() = default;

  virtual Size GetImageSize(const Packet& image_packet) = 0;

  // Converts image to tensor.
  // @image_packet contains image to extract from.
  // @roi describes region of interest within the image to extract (absolute
  // values).
  // @output_dims dimensions of output tensor.
  // @range_min/max describes output tensor range image pixels should converted
  // to.
  virtual ::mediapipe::StatusOr<Tensor> Convert(const Packet& image_packet,
                                                const RotatedRect& roi,
                                                const Size& output_dims,
                                                float range_min,
                                                float range_max) = 0;
};

}  // namespace mediapipe

#endif  // MEDIAPIPE_CALCULATORS_TENSOR_IMAGE_TO_TENSOR_CONVERTER_H_
