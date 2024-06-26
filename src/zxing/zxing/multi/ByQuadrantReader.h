#ifndef ZXING_BY_QUADRANT_READER_H
#define ZXING_BY_QUADRANT_READER_H

/*
 *  Copyright 2011 ZXing authors All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <zxing/QZXingReader.h>
#include <zxing/BinaryBitmap.h>
#include <zxing/Result.h>
#include <zxing/DecodeHints.h>

namespace zxing {
namespace multi {

class ByQuadrantReader : public QZXingReader {
  private:
    QZXingReader& delegate_;

  public:
    ByQuadrantReader(QZXingReader& delegate);
    virtual ~ByQuadrantReader();
    virtual QSharedPointer<Result> decode(QSharedPointer<BinaryBitmap> image);
    virtual QSharedPointer<Result> decode(QSharedPointer<BinaryBitmap> image, DecodeHints hints);
};

}
}

#endif // ZXING_BY_QUADRANT_READER_H
