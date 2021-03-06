#ifndef _ROBOTSIM_IO_H
#define _ROBOTSIM_IO_H

#include <string>

class Geometry3D;
class WorldModel;

/** @file robotio.h 
 * Miscelleaneous IO routines for ROS and Three.js export.
 */

/** @brief Subscribes a Geometry3D to a stream 
 * 
 * Args:
 * 
 *     g (Geometry3D): the geometry that will be updated
 *     protocol (str): only "ros" accepted for now.
 *     name (str): the name of the stream. E.g., ROS topic.
 *     type (str, optional): If provided, specifies the format of the data
 *         to be subscribed to. If not, tries to determine the type
 *         automatically.
 *
 * Only ROS point clouds (PointCloud2) are supported for now.
 * Note that you can also call ``Geometry3D.loadFile("ros://[ROS_TOPIC]")``
 * or ``Geometry3D.loadFile("ros:PointCloud2//[ROS_TOPIC]")``
 * to accomplish the same thing.
 *
 * Returns:
 *     (bool): True if successful.
 */
bool SubscribeToStream(Geometry3D& g,const char* protocol,const char* name,const char* type="");

/** @brief Unsubscribes from a stream previously subscribed to via
 * :func:`SubscribeToStream`
 */
bool DetachFromStream(const char* protocol,const char* name);

/** @brief Does some processing on stream subscriptions.
 * 
 * Args:
 * 
 *     protocol (str): either name the protocol to be updated, or "all" for
 *         updating all subscribed streams
 * 
 * Returns:
 *     (bool): True if any stream was updated.
 */
bool ProcessStreams(const char* protocol="all");

/** @brief Waits up to timeout seconds for an update on the given stream
 * 
 * Return:
 * 
 *     (bool): True if the stream was updated.
 */
bool WaitForStream(const char* protocol,const char* name,double timeout);

///Exports the WorldModel to a JSON string ready for use in Three.js
std::string ThreeJSGetScene(const WorldModel&);

///Exports the WorldModel to a JSON string ready for use in Three.js
std::string ThreeJSGetTransforms(const WorldModel&);



#endif //_ROBOTSIM_IO_H