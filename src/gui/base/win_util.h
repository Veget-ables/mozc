// Copyright 2010, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef MOZC_GUI_BASE_WIN_UTIL_H_
#define MOZC_GUI_BASE_WIN_UTIL_H_

#include <QtGui/QWidget>

#include "base/base.h"

namespace mozc {
namespace gui {

class WinUtil {
 public:
  // Qt wrapper for DwmIsCompositionEnabled
  static bool IsCompositionEnabled();

  // Qt wrapper for DwmExtendFrameIntoClientArea
  static bool ExtendFrameIntoClientArea(QWidget *widget,
                                        int left, int top,
                                        int right, int bottom);

  static bool ExtendFrameIntoClientArea(QWidget *widget) {
    return WinUtil::ExtendFrameIntoClientArea(widget, -1, -1, -1, -1);
  }

  // Return the rect which is requred to display
  // "text" on the "widget".
  static QRect GetTextRect(QWidget *widget, const QString &text);

  // Install style sheets
  static void InstallStyleSheets(const QString &dwm_on_style,
                                 const QString &dwm_off_style);

  static void InstallStyleSheetsFiles(const QString &dwm_on_style_file,
                                      const QString &dwm_off_style_file);

  // Qt Wrapper for DrawThemeTextEx:
  // Draw "text" on the center of the client "rect".
  static void DrawThemeText(const QString &text,
                            const QRect &rect,
                            int glow_size,
                            QPainter *painter);

  // Activate Window generated by the process with 'process_id'.
  static void ActivateWindow(uint32 process_id);

 private:
  WinUtil() {}
  ~WinUtil() {}
};
}  // namespace gui
}  // namespace mozc

#endif  // MOZC_GUI_BASE_WIN_UTIL_H_