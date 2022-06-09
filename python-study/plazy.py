from pathlib import Path

from requests import patch
import plazy

if __name__ == "__main__":
    files = plazy.list_files(root=Path.cwd(),
                             filter_func=lambda x: True if x.endswith(
                                 '.mdx') else False,
                             is_include_root=False)
    print(files)
