import os
import sys
import unittest
import OCCT
from os.path import abspath, dirname, split, splitext
from glob import glob

class Test_ModulesImport(unittest.TestCase):

    @unittest.skipIf("CI" in os.environ, "Disabled in CI")
    def testModulesImport(self):
        errors = []
        root = OCCT.__path__[0]

        if sys.platform == 'win32':
            ext = 'pyd'
        elif sys.platform == 'darwin':
            ext = 'dylib'
        else:
            ext = 'so'

        mods = []
        for f in glob(f'{root}/*.{ext}'):
            mod, _ = splitext(split(f)[1])
            if mod.startswith("_"):
                continue
            mods.append(f'OCCT.{mod}')
        self.assertGreater(len(mods), 0, "No modules found")
        mods.sort()

        for mod in mods:
            try:
                print(f"Importing {mod}...")
                __import__(mod)
                print(f"OK")
            except ImportError as e:
                if "Vtk" in mod or "OCCT.step" in mod:
                    pass # Ignore
                else:
                    errors.append(mod)
                print(f"Error importing {mod}:")
                print(f"  {e}")
        self.assertFalse(errors)

if __name__ == '__main__':
    unittest.main()
