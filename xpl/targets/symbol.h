#ifndef __XPL_SEMANTICS_SYMBOL_H__
#define __XPL_SEMANTICS_SYMBOL_H__

#include <string>
#include <cdk/basic_type.h>

namespace xpl {

    class symbol {
      basic_type *_type;
      std::string _name;
      long _value; // hack!

      bool _hasValue;
      bool _isUse;
      bool _isPublic;
      
    public:
      inline symbol(basic_type *type, const std::string &name, long value) :
          _type(type), _name(name), _value(value) {
      }

      virtual ~symbol() {
        delete _type;
      }

      inline basic_type *type() const {
        return _type;
      }
      inline const std::string &name() const {
        return _name;
      }
      inline long value() const {
        return _value;
      }
      inline long value(long v) {
        return _value = v;
      }
      
      inline bool hasValue(){
          return _hasValue;
      }
      
      inline bool isUse(){
          return _isUse;
      }
      
      inline bool isPublic(){
          return _isPublic;
      }
      inline void sethasValue(bool b){
          _hasValue = b;
      }
      
      inline void setisUse(bool b){
          _isUse = b;
      }
      
      inline void setisPublic(bool b){
          _isPublic = b;
      }
    };

} // xpl

#endif
