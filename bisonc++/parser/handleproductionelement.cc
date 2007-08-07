#include "parser.ih"

void Parser::handleProductionElement(PTag *last)
{
    if (!d_rules.hasRules())    // may happen if the first rule could not be
        return;                 // defined because of token/rulename clash

    if (!last)         // the last PTag was a %prec specification
    {
        checkFirstType();
        return;
    }

    switch (last->tag)
    {
        case PTag::TERMINAL:
            d_rules.addElement(last->terminal);
            checkFirstType();
        break;
        case PTag::SYMBOL:
            d_rules.addElement(last->symbol);
            checkFirstType();
        break;
        case PTag::BLOCK:
            installAction(last->block);
        break;
        case PTag::NONE:    // can't occur, but used to keep the 
        break;              // compiler from generating a warning
    }

    delete last;
}






