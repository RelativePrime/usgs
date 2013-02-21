/*
 * FileIO.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: jlriegle
 *
 *      Reads Config file
 */

#include "PredictBurnedArea.h"

#include <boost/program_options.hpp>
namespace po = boost::program_options;
using namespace boost;

bool PredictBurnedArea::loadParametersFromFile(const string filename, int ac,char* av[]) {
	po::options_description config("Configuration");
	config.add_options()
			("INPUT_HDF_FILE", po::value<string>(), "input hdf")
			("OUTPUT_FILE_NAME", po::value<string>(), "output file name")
			("INPUT_HEADER_FILE", po::value<string>(), "input header file")
			("OUTPUT_HEADER_NAME", po::value<string>(), "output header file name")
			("OUTPUT_TIFF_NAME", po::value<string>(), "output tiff file name")
			("TREE_CNT", po::value<int>(), "number of trees used for training")
			("SHRINKAGE", po::value<float>(), "shrinkage value used for training")
			("MAX_DEPTH", po::value<int>(),"maximal depth of each decision tree used for training");

	po::options_description cmdline_options;
	cmdline_options.add(config);

	po::options_description config_file_options;
	config_file_options.add(config);

	po::options_description visible("Allowed options");
	visible.add(config);

	po::variables_map vm;
	po::store(po::command_line_parser(ac, av).options(config).allow_unregistered().run(),vm);
	notify(vm);

	ifstream ifs(filename.c_str());
	if (!ifs) {
		cout << "can not open config file: " << filename << "\n";
		return (FALSE);
	} else {
		store(parse_config_file(ifs, config_file_options), vm);
		notify(vm);
	}

	if (vm.count("INPUT_HDF_FILE")) {
		if (VERBOSE) {
			cout << "Input File: " << vm["INPUT_HDF_FILE"].as<string>() << "\n";
		}
		INPUT_HDF_FILE = vm["INPUT_HDF_FILE"].as<string>();
	}

	if (vm.count("OUTPUT_FILE_NAME")) {
		if (VERBOSE) {
			cout << "Output File: " << vm["OUTPUT_FILE_NAME"].as<string>() << "\n";
		}
		OUTPUT_FILE_NAME = vm["OUTPUT_FILE_NAME"].as<string>();
	}

	if (vm.count("INPUT_HEADER_FILE")) {
		if (VERBOSE) {
			cout << "Input Header File: " << vm["INPUT_HEADER_FILE"].as<string>() << "\n";
		}
		INPUT_HEADER_FILE = vm["INPUT_HEADER_FILE"].as<string>();
	}

	if (vm.count("OUTPUT_HEADER_NAME")) {
		if (VERBOSE) {
			cout << "Output Header File: " << vm["OUTPUT_HEADER_NAME"].as<string>() << "\n";
		}
		OUTPUT_HEADER_NAME = vm["OUTPUT_HEADER_NAME"].as<string>();
	}

	if (vm.count("OUTPUT_TIFF_NAME")) {
			if (VERBOSE) {
				cout << "Output Tiff File: " << vm["OUTPUT_TIFF_NAME"].as<string>() << "\n";
			}
			OUTPUT_TIFF_NAME = vm["OUTPUT_TIFF_NAME"].as<string>();
		}

	if (vm.count("TREE_CNT")) {
		if (VERBOSE) {
			cout << "Tree Count: " << vm["TREE_CNT"].as<int>() << "\n";
		}
		TREE_CNT = vm["TREE_CNT"].as<int>();
	}

	if (vm.count("SHRINKAGE")) {
		if (VERBOSE) {
			cout << "Shrinkage: " << vm["SHRINKAGE"].as<float>() << "\n";
		}
		SHRINKAGE = vm["SHRINKAGE"].as<float>();
	}

	if (vm.count("MAX_DEPTH")) {
		if (VERBOSE) {
			cout << "Max Depth: " << vm["MAX_DEPTH"].as<int>() << "\n";
		}
		MAX_DEPTH = vm["MAX_DEPTH"].as<int>();
	}


	return (TRUE);
}
