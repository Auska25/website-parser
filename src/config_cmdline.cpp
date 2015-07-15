/*
 * config_cmdline.cpp
 *
 *  Created on: 15 Jul 2015
 *      Author: karl
 */

#include <boost/program_options.hpp>

#include "config_cmdine.hpp"

using namespace auska25;

namespace po = boost::program_options;

config_cmdline::config_cmdline(int argc, char *argv[])
{
    po::options_description desc("Allowed options");
    desc.add_options()
        ("url", po::value<std::string>(), "url to use")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if(vm.count("url"))
    {
        url_ = vm["url"].as<std::string>();
    }
}

const std::string& config_cmdline::get_url() const
{
    return url_;
}
