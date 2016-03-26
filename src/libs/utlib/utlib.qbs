import qbs 1.0
Product
{
   type: "dynamiclibrary"
   name : "utlib"
   targetName : "ut"
   Depends { 
      name: "Qt"; 
      submodules: ["core", "network","websockets", "qml"]
   }
   Depends { name:"corelib"}
   Depends { name:"cpp"}
   destinationDirectory: "lib"
   cpp.defines: {
      var defines = [];
      if(product.type == "staticlibrary"){
         defines.push("UT_STATIC_LIB");
      }else{
         defines.push("UT_LIBRARY");
      }
      defines = defines.concat([
                                  'UT_LIB_VERSION="'+ version+'"',
                                  'UT_VERSION="' + project.upgradeTesterVersion + '"'
                               ]);
      return defines;
   }
   cpp.visibility: "minimal"
   cpp.cxxLanguageVersion: "c++14"
   cpp.includePaths:[".", "../"]
   Export {
      Depends { name: "cpp" }
      Depends { name: "Qt"; submodules: ["core"] }
      cpp.rpaths: ["$ORIGIN/../lib"]
      cpp.includePaths: [product.sourceDirectory+"../"]
   }
   Group {
      fileTagsFilter: product.type.concat("dynamiclibrary_symlink")
      qbs.install: true
      qbs.installDir: "lib"
   }
   
   Group {
      name: "global"
      prefix: name + "/"
      files: [
         "const.h",
      ]
   }
   
   Group {
      name: "upgrade"
      prefix: name + "/"
      files:[
           "upgrade_env_script_object.cpp",
           "upgrade_env_script_object.h",
           "upgradeenv.cpp",
           "upgradeenv.h",
       ]
   }
}
