import qbs 1.0
UpgradeTesterApplication
{
    files: [
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
}