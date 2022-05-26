// Copyright 2022 The Dredd Project Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "libdredd/mutate_ast_consumer.h"

#include "clang/AST/ASTContext.h"
#include "clang/AST/Decl.h"
#include "clang/Basic/Diagnostic.h"

namespace dredd {

void MutateAstConsumer::HandleTranslationUnit(clang::ASTContext& context) {
  (void)compiler_instance_;
  (void)generator_;
  (void)num_mutations_;
  (void)output_file_;
  if (context.getDiagnostics().hasErrorOccurred()) {
    // There has been an error, so we don't do any processing.
    return;
  }
  visitor_->TraverseDecl(context.getTranslationUnitDecl());
}

}  // namespace dredd