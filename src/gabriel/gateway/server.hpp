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
 *   @date: 2014-01-09 12:40:31                                        *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GABRIEL__GATEWAY__SERVER
#define GABRIEL__GATEWAY__SERVER

#include <map>
#include "gabriel/base/ordinary_server.hpp"
#include "gabriel/base/message_handler.hpp"

namespace gabriel {
namespace gateway {

class Server : public gabriel::base::Ordinary_Server
{
public:
    Server();
    virtual ~Server();
    
private:
    struct Account_Info
    {
        uint32 birth_time;
        std::string key;
    };
    
    typedef Ordinary_Server Super;    
    virtual void register_msg_handler();
    virtual void on_connection_shutdown(gabriel::base::Client_Connection *client_connection);
    virtual bool on_connection_shutdown(gabriel::base::Server_Connection *server_connection);
    virtual bool verify_connection(gabriel::base::Client_Connection *client_connection);
    virtual void update_hook();
    virtual void fini_hook();
    virtual void do_main_on_server_connection();
    virtual void init_reactor();
    virtual bool init_hook();    
    virtual void do_reconnect();
    void register_rsp_from(gabriel::base::Connection *connection, void *data, uint32 size);
    void sync_account(gabriel::base::Connection *connection, void *data, uint32 size);
    std::map<uint32, gabriel::base::Server_Connection*> m_game_connections;
    std::map<std::string, Account_Info> m_accounts;
};
    
}
}

typedef ACE_Singleton<gabriel::gateway::Server, ACE_Null_Mutex> SERVER;

#endif
