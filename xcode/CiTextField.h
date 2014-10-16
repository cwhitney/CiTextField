//
//  CiTextField.h
//  CinderText
//
//  Created by Charlie Whitney on 10/13/14.
//
//

#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/TextureFont.h"

class CiTextField {
  public:
    CiTextField( std::string text, ci::Rectf bounds, ci::Font font );
    ~CiTextField();
    
    void setText( std::string text );
    void setBounds( ci::Rectf bounds );
    
    void draw();
    
    bool bUseScissorTest;
    
    ci::Vec2f       padding;
    ci::Color       mColorStroke, mColorFill, mColorText, mColorHighlight;
    
  private:
    void onMouseDown( ci::app::MouseEvent event );
    void onMouseDrag( ci::app::MouseEvent event );
    void onMouseUp( ci::app::MouseEvent event );
    
    void onKeyDown( ci::app::KeyEvent event );
    void onKeyUp( ci::app::KeyEvent event );
    
    int getCursorIndex( ci::Vec2f pos );
    
    int eraseString( int start, int end );
    
    bool            bDragging;
    bool            bActive;
    bool            bHighlighted;
    
    ci::Vec2f       mCursorPos;
    int             mCaratIndex, mCaratStart;
    
    std::string     mText;
    ci::Rectf       mBounds;
    ci::Vec2f       emSize;
    
    ci::Font                    mFont;
    ci::gl::TextureFontRef      tFont;
    
    // mouse events
    boost::signals2::scoped_connection  mMouseDownCb,
                                        mMouseDragCb,
                                        mMouseUpCb,
                                        mKeyDownCb,
                                        mKeyUpCb;
};