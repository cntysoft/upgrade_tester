import qbs 1.0
UpgradeTesterApplication
{
    files: [
        "application.cpp",
        "application.h",
        "command_runner.cpp",
        "command_runner.h",
        "main.cpp",
    ]
   name : "upgrade_tester"
   targetName : "upgrade_tester"
   Depends { name: "Qt"; submodules: ["sql"] }
   cpp.includePaths: base.concat([
                                    ".","../../libs"
                                 ])
   cpp.defines: base.concat([
                               'UPGRADE_TESTER_VERSION="' + project.upgradeTesterVersion + '"'
                            ])
   Group {
      name: "utils"
      prefix: name+"/"
      files:[
           "default_cfg_initializer.cpp",
       ]
   }
   Group {
      name: "command"
      prefix: name+"/"
      files:[
           "command_repo.h",
           "global_command.cpp",
           "global_command.h",
       ]
   }
   Group {
      name: "initializers"
      prefix: name+"/"
      files:[
           "initializer_cleanup_funcs.h",
           "global_initializer_and_cleanup.cpp",
       ]
   }
}