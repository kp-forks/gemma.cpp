// Copyright 2024 Google LLC
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_GEMMA_CPP_GEMMA_COMMON_H_
#define THIRD_PARTY_GEMMA_CPP_GEMMA_COMMON_H_

#include <stddef.h>

#include <string>

#include "gemma/configs.h"  // IWYU pragma: export
#include "hwy/base.h"  // ConvertScalarTo

namespace gcpp {

// TODO(janwas): merge with functions below.
struct ModelInfo {
  Model model;
  ModelTraining training;
  Type weight;
};

// Returns error string or nullptr if OK.
// Thread-hostile.
const char* ParseModelTypeAndTraining(const std::string& model_flag,
                                      Model& model, ModelTraining& training);
const char* ParseType(const std::string& type_string, Type& type);

// Inverse of ParseModelTypeAndTraining.
const char* ModelString(Model model, ModelTraining training);
const char* StringFromType(Type type);

void Wrap(const ModelInfo& info, size_t pos, std::string& prompt);

// ----------------------------------------------------------------------------
//

float EmbeddingScaling(size_t model_dim);

float ChooseQueryScale(const ModelConfig& config);

}  // namespace gcpp

#endif  // THIRD_PARTY_GEMMA_CPP_GEMMA_COMMON_H_
