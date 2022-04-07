#include "TH1F.h"
#include "TF1.h"
#include "TRint.h"
#include "TCanvas.h"

#include "protolib/protolib.hpp"

int main(int argc, char** argv)
{
    TRint app("App", &argc, argv);
    auto c1 = new TCanvas("c1", "Canvas", 10, 10, 900, 500);
    auto h = new TH1F("h", "test", 100, 0, 5000);

    pl::File f("/home/l_frojdh/data/protolib_test/jungfrau/run_master_0.raw");
    auto img = f.read_as<uint16_t>();
    for (auto pixel : img)
        h->Fill(pixel);

    auto func = new TF1("func", "gaus", 0, 5000);
    h->Fit("func", "SR");

    h->SetFillColor(38);
    c1->SetGrid();
    h->Draw();
    c1->Update();
    app.Run();
}
