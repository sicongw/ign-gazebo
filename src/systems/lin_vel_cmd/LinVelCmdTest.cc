#include "LinVelCmdTest.hh"

#include "ignition/gazebo/components/LinearVelocityCmd.hh"
#include "ignition/gazebo/components/Model.hh"

#include <ignition/plugin/Register.hh>

using namespace ignition;
using namespace gazebo;
using namespace systems;

LinVelCmdTest::LinVelCmdTest()
{
}

LinVelCmdTest::~LinVelCmdTest()
{
}

void LinVelCmdTest::PreUpdate(const UpdateInfo &_info,
    EntityComponentManager &_ecm)
{
  if (_info.paused)
    return;

  _ecm.Each<components::Model>(
      [&](const Entity &_entity, components::Model *) -> bool
      {
        // apply a linear velocity of 1m/s along the x axis
        _ecm.SetComponentData<components::LinearVelocityCmd>(
            _entity, {1, 0, 0});
        return true;
      });
}

IGNITION_ADD_PLUGIN(LinVelCmdTest, System,
  LinVelCmdTest::ISystemPreUpdate
)

IGNITION_ADD_PLUGIN_ALIAS(LinVelCmdTest,
  "ignition::gazebo::systems::LinVelCmdTest"
)
