
#ifndef _HEBIROS_GAZEBO_PLUGIN_HH_
#define _HEBIROS_GAZEBO_PLUGIN_HH_

#include <gazebo/common/common.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>

#include "ros/ros.h"
#include "sensor_msgs/JointState.h"
#include "std_srvs/Empty.h"

#include "hebiros/FeedbackMsg.h"
#include "hebiros/CommandMsg.h"
#include "hebiros/AddGroupFromNamesSrv.h"
#include "hebiros/SetCommandLifetimeSrv.h"
#include "hebiros/SetFeedbackFrequencySrv.h"

#include "hebiros_gazebo_group.h"
#include "hebiros_gazebo_joint.h"
#include "hebiros_gazebo_controller.h"

using namespace hebiros;
using namespace gazebo;

class HebirosGazeboPlugin: public ModelPlugin {

  public:
    HebirosGazeboPlugin();
    ~HebirosGazeboPlugin();
    void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);
    void OnUpdate(const common::UpdateInfo & _info);

  private:
    int command_lifetime = 100;
    int feedback_frequency = 100;

    physics::ModelPtr model;
    event::ConnectionPtr update_connection;
    std::map<std::string, std::shared_ptr<HebirosGazeboGroup>> hebiros_groups;
    std::map<std::string, std::shared_ptr<HebirosGazeboJoint>> hebiros_joints;
    HebirosGazeboController controller;
    bool check_acknowledgement;
    bool acknowledgement;

    std::shared_ptr<ros::NodeHandle> n;
    ros::Subscriber command_sub;
    ros::ServiceServer add_group_srv;
    ros::ServiceServer acknowledge_srv;
    ros::ServiceServer command_lifetime_srv;
    ros::ServiceServer feedback_frequency_srv;

    void AddJoint(std::string joint_name);
    void UpdateJoint(std::string joint_name, physics::JointPtr joint);

    void SubCommand(const boost::shared_ptr<CommandMsg const> data);
    bool SrvAddGroup(AddGroupFromNamesSrv::Request &req,
      AddGroupFromNamesSrv::Response &res);
    bool SrvAcknowledge(std_srvs::Empty::Request &req,
      std_srvs::Empty::Response &res);
    bool SrvSetCommandLifetime(SetCommandLifetimeSrv::Request &req,
      SetCommandLifetimeSrv::Response &res);
    bool SrvSetFeedbackFrequency(SetFeedbackFrequencySrv::Request &req,
      SetFeedbackFrequencySrv::Response &res);

};


#endif
