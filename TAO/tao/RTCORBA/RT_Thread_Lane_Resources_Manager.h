//=============================================================================
/**
 *  @file    RT_Thread_Lane_Resources_Manager.h
 *
 *  $Id$
 *
 *  @author  Irfan Pyarali
 */
// ===================================================================

#ifndef TAO_RT_THREAD_LANE_RESOURCES_MANAGER_H
#define TAO_RT_THREAD_LANE_RESOURCES_MANAGER_H

#include "ace/pre.h"
#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/RTCORBA/rtcorba_export.h"
#include "tao/Thread_Lane_Resources_Manager.h"
#include "ace/Service_Config.h"

class TAO_Thread_Pool_Manager;

/**
 * @class TAO_RT_Thread_Lane_Resources_Manager
 *
 * @brief Simple manager for thread lane resources.
 *
 * \nosubgrouping
 *
 **/
class TAO_RTCORBA_Export TAO_RT_Thread_Lane_Resources_Manager :
  public TAO_Thread_Lane_Resources_Manager
{
public:
  TAO_RT_Thread_Lane_Resources_Manager (void);
  ~TAO_RT_Thread_Lane_Resources_Manager (void);

  int initialize (TAO_ORB_Core &orb_core);
  void finalize (void);

  int open_default_resources (CORBA_Environment &ACE_TRY_ENV);

  TAO_Thread_Lane_Resources &lane_resources (void);
  TAO_Thread_Lane_Resources &default_lane_resources (void);
  int shutdown_all_reactors (CORBA_Environment &ACE_TRY_ENV);

  /// Get the Thread Pool Manager.
  TAO_Thread_Pool_Manager &tp_manager (void);

protected:

  int shutdown_default_reactors (CORBA_Environment &ACE_TRY_ENV);

  /// Mutual exclusion for calling open.
  TAO_SYNCH_MUTEX open_lock_;

  /// Flag which denotes that the open method was called.
  int open_called_;

  TAO_Thread_Lane_Resources *default_lane_resources_;

  /// Thread Pool Manager.
  TAO_Thread_Pool_Manager *tp_manager_;
};

ACE_STATIC_SVC_DECLARE_EXPORT (TAO_RTCORBA, TAO_RT_Thread_Lane_Resources_Manager)
ACE_FACTORY_DECLARE (TAO_RTCORBA, TAO_RT_Thread_Lane_Resources_Manager)

#if defined (__ACE_INLINE__)
# include "tao/RT_Thread_Lane_Resources_Manager.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"

#endif /* TAO_RT_THREAD_LANE_RESOURCES_MANAGER_H */
