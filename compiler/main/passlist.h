#ifndef _PASSLIST_H_
#define _PASSLIST_H_

//#define USE_EXPR_VARINIT

/* This is the default list of passes that will be run by the
   compiler.  The passes shown will be run in the order shown,
   and their arguments will be set to the quoted string that
   follows.

   This file may be saved and fed to the compiler using the
   --passlist argument to specify a different set of passes
   dynamically.
*/

PassInfo passlist[] = {
  FIRST,

  // passes to create the basic AST
  RUN(FilesToAST, ""),
  RUN(CreateEntryPoint, ""),
  RUN(Fixup, ""),
  RUN(Fixup, "verify"), // this is a sanity check

  // passes to run if --noanalysis is used
  RUN(OmitForNoAnalysis, ""),

  // passes to normalize the basic AST
  RUN(ExpandClassWiths, ""),
  RUN(InsertThisParameters, ""),
  RUN(ScopeResolveSymbols, ""),
  RUN(RenameOverloadedFunctions, ""),
  RUN(InsertAnonymousDomains, ""),
  RUN(InsertAnonymousTypes, ""),
  RUN(InsertIndexType, ""),
  RUN(BuildClassConstructorsEtc, ""),
  RUN(SpecializeParenOpExprs, ""),
  RUN(ApplyThisParameters, ""),
#ifdef USE_EXPR_VARINIT
  RUN(ProcessDefs, ""),
#endif
  RUN(RemoveLikeTypes, ""),

  // passes to collect information for analysis
  RUN(Fixup, "verify"), // this is a sanity check
  RUN(VerifyASTType, ""),
  RUN(ComputeVisibleFunctions, ""),

  // passes to run analysis
  RUN(Fixup, "verify"), // this is a sanity check
  RUN(RunAnalysis, ""),

  // passes to capture analysis information in the AST
  RUN(Fixup, "verify"), // this is a sanity check
  RUN(RemoveDeadSymbols, ""),
  RUN(ResolveSymbols, ""),
  RUN(FindUnknownTypes, ""),
  RUN(RemoveTypeVariableActuals, ""),
  RUN(RemoveTypeVariableFormals, ""),
  RUN(ResolveOverloadedOperators, ""),
  RUN(RemoveNamedParameters, ""),

  // passes to normalize the basic AST after analysis
  RUN(Fixup, "verify"), // this is a sanity check
  RUN(InsertWriteFns, ""),
  RUN(InsertFunctionTemps, ""),
  RUN(TransformLetExprs, ""),
  RUN(InsertElidedLoops, ""),

  // check the program's semantics
  RUN(Fixup, "verify"), // this is a sanity check
  RUN(CheckSemantics, ""),

  // eventually, optimizations will go here

  // passes to prepare for C code generation
  RUN(Fixup, "verify"), // this is a sanity check
  RUN(MethodsToFunctions, ""),
  RUN(ProcessParameters, ""),
#ifndef USE_EXPR_VARINIT
  RUN(InsertVariableInitializations, ""),
#endif
  RUN(DestructureTupleAssignments, ""),
  RUN(ExpandSeqExprAssignments, ""),
  RUN(InsertUnionChecks, ""),
  RUN(LegalizeCNames, ""), 

  // passes to generate code and compile
  RUN(Fixup, "verify"), // this is a sanity check
  RUN(Codegen, ""),
  RUN(BuildBinary, ""),

  LAST
};

#endif
