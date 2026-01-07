#pragma once

#include <string>
#include <map>
#include <utility>

#include "TokenEnums.h"

namespace Vex {
    struct Token {
        ETokenType  Type;
        std::string Lexeme;
        int         Line;
        int         Column;

        union {
            long long   IntValue;
            double      FloatValue;
        };

        Token(const ETokenType Type, std::string  Lexeme, int Line, int Column)
            : Type(Type)
            , Lexeme(std::move(Lexeme))
            , Line(Line)
            , Column(Column)
            , IntValue(0)
        {}

        [[nodiscard]] std::string ToString() const;
    };

    static const std::map<std::string, ETokenType> Keywords = {
        { "Define",     ETokenType::DEFINE      },
        { "Fetch",      ETokenType::FETCH       },
        { "Set",        ETokenType::SET         },
        { "Interface",  ETokenType::INTERFACE   },
        { "Namespace",  ETokenType::NAMESPACE   },
        { "Using",      ETokenType::USING       },

        { "Public",     ETokenType::PUBLIC      },
        { "Private",    ETokenType::PRIVATE     },
        { "Protected",  ETokenType::PROTECTED   },
        { "View",       ETokenType::VIEW        },

        { "if",         ETokenType::IF          },
        { "else",       ETokenType::ELSE        },
        { "for",        ETokenType::FOR         },
        { "while",      ETokenType::WHILE       },
        { "do",         ETokenType::DO          },
        { "match",      ETokenType::MATCH       },
        { "break",      ETokenType::BREAK       },
        { "continue",   ETokenType::CONTINUE    },
        { "return",     ETokenType::RETURN      },

        { "Unique",     ETokenType::UNIQUE      },
        { "Shared",     ETokenType::SHARED      },
        { "Borrow",     ETokenType::BORROW      },
        { "Raw",        ETokenType::RAW         },
        { "Unsafe",     ETokenType::UNSAFE      },

        { "Var",        ETokenType::VAR         },
        { "Let",        ETokenType::LET         },
        { "Const",      ETokenType::CONST       },
        { "Static",     ETokenType::STATIC      },

        { "Override",   ETokenType::OVERRIDE    },
        { "Virtual",    ETokenType::VIRTUAL     },
        { "Implement",  ETokenType::IMPLEMENT   },
        { "Operator",   ETokenType::OPERATOR    },

        { "true",       ETokenType::TRUE        },
        { "false",      ETokenType::FALSE       },

        { "new",        ETokenType::NEW         },
        { "as",         ETokenType::AS          },
        { "is",         ETokenType::IS          },
        { "in",         ETokenType::IN          },
        { "step",       ETokenType::STEP        },
        { "super",      ETokenType::SUPER       },
        { "this",       ETokenType::THIS        },
        { "global",     ETokenType::GLOBAL      },
        { "null",       ETokenType::NULL_KEY    },

        { "Int_8",      ETokenType::INT8        },
        { "Int_16",     ETokenType::INT16       },
        { "Int_32",     ETokenType::INT32       },
        { "Int_64",     ETokenType::INT64       },
        { "Uint_8",     ETokenType::UINT8       },
        { "Uint_16",    ETokenType::UINT16      },
        { "Uint_32",    ETokenType::UINT32      },
        { "Uint_64",    ETokenType::UINT64      },
        { "Float_32",   ETokenType::FLOAT32     },
        { "Float_64",   ETokenType::FLOAT64     },
        { "Int",        ETokenType::INT         },
        { "Uint",       ETokenType::UINT        },
        { "Float",      ETokenType::FLOAT       },
        { "Double",     ETokenType::DOUBLE      },
        { "Bool",       ETokenType::BOOL        },
        { "Char",       ETokenType::CHAR        },
        { "String",     ETokenType::STRING      },
        { "Void",       ETokenType::VOID        },

        { "Vector2",    ETokenType::VECTOR2     },
        { "Vector3",    ETokenType::VECTOR3     },
        { "Vector4",    ETokenType::VECTOR4     },
        { "Quat",       ETokenType::QUATERNION  },
        { "Color",      ETokenType::COLOR       },
        { "Transform",  ETokenType::TRANSFORM   },
    };
}