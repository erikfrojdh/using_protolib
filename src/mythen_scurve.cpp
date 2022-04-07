#include "TGraph.h"
#include "TRint.h"
#include "TCanvas.h"
#include <vector>

#include "protolib/protolib.hpp"

#include <iostream>
#include <numeric>

int main(int argc, char** argv)
{
    TRint app("App", &argc, argv);
    auto c1 = new TCanvas("c1", "Canvas", 10, 10, 900, 500);
    
    pl::File f("/home/l_frojdh/data/testModule20220404/Sn_100ms_200V_standard_master_4.json");
    size_t n = f.total_frames();
    auto shape = f.shape();

    std::cout << "Frames: " << n << "\nRows: " << shape[0] << "\nCols: " << shape[1] << '\n';

    std::vector<double> x(n);
    std::vector<double> y(n);

    for (size_t i=0; i!=n; ++i){
        auto img = f.read_as<uint32_t>();
        y[i] = std::accumulate(img.begin(), img.end(), 0UL); //sum all channels
        x[i] = i;
    }


    auto g = new TGraph(n,x.data(),y.data());


    c1->SetGrid();
    g->Draw();
    c1->Update();
    app.Run();
}
