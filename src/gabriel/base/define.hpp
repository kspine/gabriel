/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *      _____       ___   _____   _____    _   _____   _               *
 *     /  ___|     /   | |  _  \ |  _  \  | | | ____| | |              *
 *     | |        / /| | | |_| | | |_| |  | | | |__   | |              *
 *     | |  _    / / | | |  _  { |  _  /  | | |  __|  | |              *
 *     | |_| |  / /  | | | |_| | | | \ \  | | | |___  | |___           *
 *     \_____/ /_/   |_| |_____/ |_|  \_\ |_| |_____| |_____|          *
 *                                                                     *
 *     gabriel is an angel from the Holy Bible, this engine is named   *
 *   gabriel, means bringing people good news. the goal of gabriel     *
 *   server engine is to help people to develop various online games,  *
 *   welcome you to join in.                                           *
 *                                                                     *
 *   @author: lichuan                                                  *
 *   @qq: 308831759                                                    *
 *   @email: 308831759@qq.com                                          *
 *   @site: www.lichuan.me                                             *
 *   @github: https://github.com/lichuan/gabriel                       *
 *   @date: 2013-11-29 09:00:15                                        *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GABRIEL__BASE__DEFINE
#define GABRIEL__BASE__DEFINE

#include "ace/Basic_Types.h"

typedef ACE_INT8 int8;
typedef ACE_UINT8 uint8;
typedef ACE_INT16 int16;
typedef ACE_UINT16 uint16;
typedef ACE_INT32 int32;
typedef ACE_UINT32 uint32;
typedef ACE_INT64 int64;
typedef ACE_UINT64 uint64;

#define MIN_INT8 ACE_CHAR_MIN
#define MAX_INT8 ACE_CHAR_MAX
#define MAX_UINT8 ACE_OCTET_MAX

#define MIN_INT16 ACE_INT16_MIN
#define MAX_INT16 ACE_INT16_MAX
#define MAX_UINT16 ACE_UINT16_MAX

#define MIN_INT32 ACE_INT32_MIN
#define MAX_INT32 ACE_INT32_MAX
#define MAX_UINT32 ACE_UINT32_MAX

#define MIN_INT64 ACE_INT64_MIN
#define MAX_INT64 ACE_INT64_MAX
#define MAX_UINT64 ACE_UINT64_MAX

#define MIN_FLOAT ACE_FLT_MIN
#define MAX_FLOAT ACE_FLT_MAX

#define MIN_DOUBLE ACE_DBL_MIN
#define MAX_DOUBLE ACE_DBL_MAX

#define PARSE_FROM_ARRAY(Msg, msg, data, size)  \
    Msg msg;                                    \
                                                \
    if(!msg.ParseFromArray(data, size))         \
    {                                           \
        return;                                 \
    }

#define PARSE_FROM_STRING(Msg, msg, string)     \
    Msg msg;                                    \
                                                \
    if(!msg.ParseFromString(string))            \
    {                                           \
        return;                                 \
    }

namespace gabriel {
namespace base {

const uint32 RECV_REQUEST_SIZE = 1024;
const uint32 MSG_QUEUE_HWM = 2 * 1024 * 1024;
const uint32 MSG_QUEUE_LWM = MSG_QUEUE_HWM;

enum SERVER_TYPE
{
    SUPERCENTER_SERVER = 0,
    SUPERRECORD_SERVER = 1,
    CENTER_SERVER = 2,
    RECORD_SERVER = 3,
    LOGIN_SERVER = 4,
    GAME_SERVER = 5,
    GATEWAY_SERVER = 6,
};
    
enum CLIENT_TYPE
{
    INVALID_CLIENT = 0,
    SUPERRECORD_CLIENT = SUPERRECORD_SERVER,
    CENTER_CLIENT = CENTER_SERVER,
    RECORD_CLIENT = RECORD_SERVER,
    LOGIN_CLIENT = LOGIN_SERVER,
    GAME_CLIENT = GAME_SERVER,
    GATEWAY_CLIENT = GATEWAY_SERVER,
};

struct CONNECTION_STATE
{
    static const uint32 INVALID = 0;    
    static const uint32 CONNECTED = 1;
    static const uint32 SHUTTING_DOWN = 2;
    static const uint32 SHUTTING_DOWN_1 = 3;
    static const uint32 SHUTDOWN = 4;
};
    
struct SERVER_STATE
{
    static const uint32 INVALID = 0;
    static const uint32 RUNNING = 1;
    static const uint32 SHUTTING_DOWN = 2;
    static const uint32 SHUTDOWN = 3;
};
    
}
}

#endif
