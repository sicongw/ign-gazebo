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

void LinVelCmdTest::Configure(const Entity &_entity,
    const std::shared_ptr<const sdf::Element> &sdf,
    EntityComponentManager& ecm, EventManager&)
{
  ent = _entity;
   if (!ecm.EntityHasComponentType(_entity,
     components::LinearVelocityCmd().TypeId()))
     ecm.CreateComponent(_entity, components::LinearVelocityCmd());

}

void LinVelCmdTest::PreUpdate(const UpdateInfo &_info,
    EntityComponentManager &_ecm)
{
  if (_info.paused)
    return;

  auto lin_vel_cmp = _ecm.Component<components::LinearVelocityCmd>(ent);
  auto lin_vel = lin_vel_cmp->Data()[0];

  lin_vel = std::min(lin_vel + 0.01, 2.0);

  igndbg << "Setting velocity " << lin_vel << " to entity " << ent << std::endl;
  _ecm.SetComponentData<components::LinearVelocityCmd>(
      ent, {lin_vel, 0, 0});
}

IGNITION_ADD_PLUGIN(LinVelCmdTest, System,
  LinVelCmdTest::ISystemConfigure,
  LinVelCmdTest::ISystemPreUpdate
)

IGNITION_ADD_PLUGIN_ALIAS(LinVelCmdTest,
  "ignition::gazebo::systems::LinVelCmdTest"
)
