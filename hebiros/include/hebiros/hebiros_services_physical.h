#ifndef HEBIROS_SERVICES_PHYSICAL_H
#define HEBIROS_SERVICES_PHYSICAL_H

#include "ros/ros.h"

#include "hebiros/EntryListSrv.h"
#include "hebiros/AddGroupFromNamesSrv.h"
#include "hebiros/AddGroupFromURDFSrv.h"
#include "hebiros/SizeSrv.h"
#include "hebiros/SetFeedbackFrequencySrv.h"
#include "hebiros/SetCommandLifetimeSrv.h"
#include "hebiros/SendCommandWithAcknowledgementSrv.h"

#include "hebiros_services.h"
#include "lookup.hpp"

using namespace hebi;
using namespace hebiros;


class HebirosServicesPhysical : public HebirosServices {

  public:

    Lookup lookup;

    void registerNodeServices();

    void registerGroupServices(std::string group_name);

    bool entryList(
      EntryListSrv::Request &req, EntryListSrv::Response &res);

    bool addGroupFromNames(
      AddGroupFromNamesSrv::Request &req, AddGroupFromNamesSrv::Response &res);

    bool addGroupFromURDF(
      AddGroupFromURDFSrv::Request &req, AddGroupFromURDFSrv::Response &res);

    bool size(
      SizeSrv::Request &req, SizeSrv::Response &res, std::string group_name);

    bool setFeedbackFrequency(
      SetFeedbackFrequencySrv::Request &req, SetFeedbackFrequencySrv::Response &res,
      std::string group_name);

    bool setCommandLifetime(
      SetCommandLifetimeSrv::Request &req, SetCommandLifetimeSrv::Response &res,
      std::string group_name);

    bool sendCommandWithAcknowledgement(
      SendCommandWithAcknowledgementSrv::Request &req, 
      SendCommandWithAcknowledgementSrv::Response &res, std::string group_name);
};

#endif
