/*
 * Copyright (C) 2021 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef IGNITION_GAZEBO_SYSTEMS_TESTHELPERSYSTEM_HH_
#define IGNITION_GAZEBO_SYSTEMS_TESTHELPERSYSTEM_HH_

#include "ignition/gazebo/System.hh"
#include <ignition/utils/ImplPtr.hh>

namespace ignition
{
namespace gazebo
{
// Inline bracket to help doxygen filtering.
inline namespace IGNITION_GAZEBO_VERSION_NAMESPACE {
namespace systems
{
class TestHelperSystem :
  public gazebo::System,
  public gazebo::ISystemPreUpdate,
  public gazebo::ISystemUpdate,
  public gazebo::ISystemPostUpdate
{
  /// \brief Non-const callback type (for PreUpdate and Update)
  public: using CallbackType = std::function<void(
          const gazebo::UpdateInfo &, gazebo::EntityComponentManager &)>;

  /// \brief Const callback type (for PostUpdate)
  public: using CallbackTypeConst =
          std::function<void(const gazebo::UpdateInfo &,
                             const gazebo::EntityComponentManager &)>;

  /// \brief Constructor
  public: TestHelperSystem();

  /// \brief Destructor
  public: ~TestHelperSystem() = default;

  // Documentation inherited
  public: void PreUpdate(const gazebo::UpdateInfo &_info,
                gazebo::EntityComponentManager &_ecm) override;

  // Documentation inherited
  public: void Update(const gazebo::UpdateInfo &_info,
                gazebo::EntityComponentManager &_ecm) override;

  // Documentation inherited
  public: void PostUpdate(const gazebo::UpdateInfo &_info,
              const gazebo::EntityComponentManager &_ecm) override;

  public: void SetPreUpdateCallback(const CallbackType &_cb);

  /// \internal
  /// \brief Pointer to private data.
  IGN_UTILS_UNIQUE_IMPL_PTR(dataPtr)
};
}
}
}
}

#endif
