
#include <protolib/protolib.hpp>

int main(){

    std::string fname = "/Users/erik/data/protolib_test/mythen3/TiScan_master_0.raw";

    pl::File file(fname);
    for (auto& frame : file)
        ;
        //do something


}