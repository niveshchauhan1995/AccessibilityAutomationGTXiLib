//
// Copyright 2020 Google Inc.
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
//

#ifndef GTXILIB_OOPCLASSES_NO_LABEL_CHECK_H_
#define GTXILIB_OOPCLASSES_NO_LABEL_CHECK_H_

#include "check.h"
#include "ui_element.h"

namespace gtx {

// Check for detecting missing accessibility labels.
class NoLabelCheck : public Check {
 public:
  NoLabelCheck(const std::string &name) : Check(name) {}

  bool CheckElement(const UIElement &element, const Parameters &params,
                    ErrorMessage *errorMessage) const override {
    return !element.ax_label().empty();
  }
};

}  // namespace gtx

#endif  // GTXILIB_OOPCLASSES_NO_LABEL_CHECK_H_
