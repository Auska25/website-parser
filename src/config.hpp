/*
 * config.hpp
 *
 *  Created on: 15 Jul 2015
 *      Author: karl
 */

#ifndef SRC_CONFIG_HPP_
#define SRC_CONFIG_HPP_

#include <string>

namespace auska25
{

class config
{
public:

    virtual ~config()
    {
        // do nothing;
    };

    virtual const std::string& get_url() const = 0;
};

} //namespace auska25

#endif /* SRC_CONFIG_HPP_ */
