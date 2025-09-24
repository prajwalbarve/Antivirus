// hash_util.cpp
#include "hash_util.h"
#include "sha256.h"
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

string hashFileSHA256(const string& filepath) {
	ifstream file(filepath, ios::binary);
	if (!file)return "";
	
	SHA256_CTX ctx;
	sha256_init(&ctx);

	vector<char> buffer(8192);
	while (file.read(buffer.data(), buffer.size()) || file.gcount()) {
		sha256_update(&ctx, reinterpret_cast<const BYTE*>(buffer.data()), file.gcount());
	}
	BYTE hash[32];
	sha256_final(&ctx, hash);
	
	ostringstream result;
	for (int i = 0; i < 32; ++i) {
		result << hex << setw(2) << setfill('0') << (int)hash[i];
	}

	return result.str();
}