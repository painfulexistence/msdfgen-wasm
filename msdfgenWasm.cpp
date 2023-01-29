#include "msdfgen.h"
#include "msdfgen-ext.h"

#ifdef __EMSCRIPTEN__ 
#include "emscripten.h"
#endif

#include <iostream>
#include <stdlib.h>
#include <vector>

const char myCharSet[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
}; 

#ifdef __EMSCRIPTEN__ 
EMSCRIPTEN_KEEPALIVE
#endif
extern "C" {
void generateMSDFTexture(std::vector<unsigned char> fontData) {
    msdfgen::FreetypeHandle* ft = msdfgen::initializeFreetype();
    if (ft) {
        msdfgen::FontHandle* font = msdfgen::loadFontData(ft, fontData.data(), fontData.size());
        if (font) {
            msdfgen::Shape shape;
            if (msdfgen::loadGlyph(shape, font, 'A')) {
                shape.normalize();
                msdfgen::Bitmap<float, 3> msdf(32, 32);
                msdfgen::generateMSDF(msdf, shape, 4.0, 1.0, msdfgen::Vector2(0, 0));
                msdfgen::savePng(msdf, "font.png");
            }
            msdfgen::destroyFont(font);
        }
        msdfgen::deinitializeFreetype(ft);
    }
}
}

#ifdef __EMSCRIPTEN__ 
EMSCRIPTEN_KEEPALIVE
#endif
extern "C" {
void test() {
    std::cout << "Hello msdfgen-wasm!" << std::endl;
}
}