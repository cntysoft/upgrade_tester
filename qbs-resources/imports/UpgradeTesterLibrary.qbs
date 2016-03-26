import qbs 1.0
UpgradeTesterProduct
{
   Depends { name:"cpp"}
   type: "dynamiclibrary"
   destinationDirectory: project.libDirName
   cpp.defines: base.concat(type == "staticlibrary" ? ["UT_STATIC_LIB"] : ["UT_LIBRARY"])
   cpp.visibility: "minimal"
   cpp.cxxLanguageVersion: "c++14"
   Group {
      fileTagsFilter: product.type.concat("dynamiclibrary_symlink")
      qbs.install: true
      qbs.installDir: project.libInstallDir
   }
   Export {
      Depends { name: "cpp" }
      Depends { name: "Qt"; submodules: ["core"] }
      cpp.rpaths: project.libRPaths
      cpp.includePaths: [product.sourceDirectory]
   }
}
