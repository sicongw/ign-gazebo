#ifndef SYSTEM_PLUGIN_LINVELCMDTEST_HH_
#define SYSTEM_PLUGIN_LINVELCMDTEST_HH_

#include "ignition/gazebo/config.hh"
#include "ignition/gazebo/System.hh"

namespace ignition
{
namespace gazebo
{
  class LinVelCmdTest:
    public System,
    public ISystemConfigure,
    public ISystemPreUpdate
  {
    public: LinVelCmdTest();

    public: ~LinVelCmdTest() override;

    public: void PreUpdate(const UpdateInfo &_info,
                EntityComponentManager &_ecm) final;

    public: void Configure(const Entity &_entity,
                const std::shared_ptr<const sdf::Element> &sdf,
                EntityComponentManager& ecm, EventManager&);

    private: Entity ent;
  };
}
}

#endif
