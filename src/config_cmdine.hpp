/*
 * config_cmdine.hpp
 *
 *  Created on: 15 Jul 2015
 *      Author: karl
 */

#ifndef SRC_CONFIG_CMDINE_HPP_
#define SRC_CONFIG_CMDINE_HPP_

#include "config.hpp"

namespace auska25 {

class config_cmdline : public config
{
public:

    config_cmdline(int argc, char *argv[]);

    virtual ~config_cmdline()
    {
        // do nothing
    };

    virtual const std::string& get_url() const;

private:
    std::string url_;
};

}


#endif /* SRC_CONFIG_CMDINE_HPP_ */
