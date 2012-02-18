#include "generator.ih"

Generator::Generator(Rules const &rules)
:
    d_arg(Arg::instance()),
    d_rules(rules),
    d_options(Options::instance()),
    d_baseClassScope(d_options.className() + "Base::"),
    d_nameSpace(d_options.nameSpace()),
    d_matchedTextFunction(d_options.scannerMatchedTextFunction()),
    d_tokenFunction(d_options.scannerTokenFunction()),

    d_debug(d_options.debug()),
    d_printTokens(d_options.printTokens()),

    d_writer(d_baseClassScope, rules)
{}
