import qbs 1.0
UpgradeTesterProduct
{
   Depends {name:"cpp"}
   Depends { name: "corelib"}
   Depends { name: "utlib"}
   type : "application"
   consoleApplication: true
   destinationDirectory: "bin"
   cpp.cxxLanguageVersion: "c++14"
   cpp.defines: {
      var defines = [];
      var resourceDir;
      var installRoot;
      if(qbs.buildVariant == "debug"){
         resourceDir = 'UT_SHARE_RES_DIR="' + qbs.installRoot+'/'+project.resourcesInstallDir+ '"';
         installRoot = 'UT_INSTALL_ROOT="' + qbs.installRoot + '"';
      }else{
         resourceDir = 'UT_SHARE_RES_DIR="' + project.installRoot+'/'+project.resourcesInstallDir+ '"';
         installRoot = 'UT_INSTALL_ROOT="' + project.installRoot + '"';
      }
      defines = defines.concat([
                                  installRoot,
                                  resourceDir,
                               ]);
      return defines;
   }
   Group {
      fileTagsFilter: product.type
      qbs.install: true
      qbs.installDir: project.appInstallDir
   }
}
