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

#include "toolkit.h"

#include <memory>
#include <string>
#include <vector>

#include "accessibility_label_not_punctuated_check.h"
#include "contrast_check.h"
#include "minimum_tappable_area_check.h"
#include "no_label_check.h"

namespace gtx {

std::unique_ptr<Toolkit> Toolkit::ToolkitWithAllDefaultChecks() {
  auto toolkit = std::make_unique<Toolkit>();
  std::unique_ptr<Check> no_label_check(new NoLabelCheck("NoLabelCheck"));
  toolkit->RegisterCheck(no_label_check);
  std::unique_ptr<Check> minimum_tappable_area_check(
      new MinimumTappableAreaCheck("MinimumTappableAreaCheck"));
  toolkit->RegisterCheck(minimum_tappable_area_check);
  std::unique_ptr<Check> contrast_check(new ContrastCheck("ContrastCheck"));
  toolkit->RegisterCheck(contrast_check);
  std::unique_ptr<Check> accessibility_label_not_punctuated(
      new AccessibilityLabelNotPunctuatedCheck(
          "AccessibilityLabelNotPunctuatedCheck"));
  toolkit->RegisterCheck(accessibility_label_not_punctuated);
  return toolkit;
}

void Toolkit::RegisterCheck(std::unique_ptr<Check> &check) {
  // Look for duplicate checks before adding a new check.
  const std::string &check_name = check->name();
  for (const auto &registered_check : registered_checks_) {
    const std::string &registered_check_name = registered_check->name();
    assert(check_name != registered_check_name);
  }

  registered_checks_.push_back(std::move(check));
}

const gtx::Check &Toolkit::GetRegisteredCheckNamed(
    const std::string &check_name) const {
  for (auto &check : registered_checks_) {
    if (check->name() == check_name) {
      return *check;
    }
  }
  assert(false);
  Check *null_check = nullptr;
  return *null_check;
}

std::vector<CheckResult> Toolkit::CheckElement(const UIElement &element,
                                               const Parameters &params) {
  std::vector<CheckResult> result;
  if (!element.is_ax_element()) {
    // Currently all checks are only applicable to accessibility elements.
    return result;
  }

  for (const auto &check : registered_checks_) {
    ErrorMessage single_check_result;
    if (!check->CheckElement(element, params, &single_check_result)) {
      result.push_back(
          CheckResult(single_check_result, nullptr, check->name()));
    }
  }
  return result;
}

std::vector<CheckResult> Toolkit::CheckElements(
    const std::vector<UIElement> &elements, const Parameters &params) {
  std::vector<CheckResult> result;
  for (const auto &element : elements) {
    auto errors = CheckElement(element, params);
    if (!errors.empty()) {
      result.insert(result.end(), errors.begin(), errors.end());
    }
  }
  return result;
}

}  // namespace gtx
