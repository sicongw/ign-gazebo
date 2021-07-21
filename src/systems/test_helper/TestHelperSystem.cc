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
#include "TestHelperSystem.hh"

#include <ignition/plugin/Register.hh>

class ignition::gazebo::systems::TestHelperSystem::Implementation
{
  public: size_t preUpdateCallCount {0};
  public: size_t updateCallCount {0};
  public: size_t postUpdateCallCount {0};

  public: CallbackType preUpdateCallback;
  public: CallbackType updateCallback;
  public: CallbackTypeConst postUpdateCallback;
};

using namespace ignition;
using namespace gazebo;
using namespace systems;

/////////////////////////////////////////////////
TestHelperSystem::TestHelperSystem()
  : dataPtr(utils::MakeUniqueImpl<Implementation>())
{
}

/////////////////////////////////////////////////
void TestHelperSystem::PreUpdate(const gazebo::UpdateInfo &_info,
      gazebo::EntityComponentManager &_ecm)
{
  ++this->dataPtr->preUpdateCallCount;
  if (this->dataPtr->preUpdateCallback)
    this->dataPtr->preUpdateCallback(_info, _ecm);
}

/////////////////////////////////////////////////
void TestHelperSystem::Update(const gazebo::UpdateInfo &_info,
      gazebo::EntityComponentManager &_ecm)
{
  ++this->dataPtr->updateCallCount;
  if (this->dataPtr->updateCallback)
    this->dataPtr->updateCallback(_info, _ecm);
}

/////////////////////////////////////////////////
void TestHelperSystem::PostUpdate(const gazebo::UpdateInfo &_info,
    const gazebo::EntityComponentManager &_ecm)
{
  ++this->dataPtr->postUpdateCallCount;
  if (this->dataPtr->postUpdateCallback)
    this->dataPtr->postUpdateCallback(_info, _ecm);
}

/////////////////////////////////////////////////
void TestHelperSystem::SetPreUpdateCallback(const CallbackType &_cb)
{
  this->dataPtr->preUpdateCallback = _cb;
}

IGNITION_ADD_PLUGIN(TestHelperSystem, System,
    TestHelperSystem::ISystemPreUpdate,
    TestHelperSystem::ISystemUpdate,
    TestHelperSystem::ISystemPostUpdate)

