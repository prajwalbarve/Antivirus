//Scanner.cpp
#inclulde <iostream>
#include <filesystem>
#include "signatures.h"
#include "hash_util.h"

using namespace std;
using namespace fs = filesystem;

void scanDicrectory(const string& path) {
	cout << "Scanning directory: " << path << endl;

	for (const auto& entry : fs::recursive_directory_iterator(path)) {
		if (!entry.is_regular_file()) continue;

		string filepath = entry.path().string();
		string filehash = hashFileSHA256(filepath);

		if (filehash.empty()) {
			cout << "[ERROR] Could not read file: " << filepath << endl;
			continue;
		}
		auto it = malware_signatures.find(filehash);
		if (it != malware_signatures.end()) {
			cout << "[ALERT] Malware detected: " << filepath << " -> " << it->second<<endl;
		}
		else {
			cout << "[OK] " << filepath << " is clean. " << endl;

		}
	}
}