import os
import random
from pathlib import Path
import shutil

BASE_DIR    = Path(os.path.dirname(os.path.abspath(__file__))) / "formai_all_vulnerable_code"
OUTPUT_DIR  = Path("sampled_code")
SAMPLES_PER_BUCKET = 5

vulnerability_subtypes = {
    "dereference-failure": [
        "dereference-failure",
    ],
    "buffer-overflow": [
        "buffer-overflow-on-scanf",
        "buffer-overflow-on-fscanf",
        "buffer-overflow-on-sscanf",
        "buffer-overflow-on-gets",
    ],
    "out-of-bounds": [
        "array-bounds-violated"
    ],
    "use-after-free": [
        "operand-of-free-must-have-zero-pointer-offset"
    ],
    "integer-overflow": [
        "arithmetic-overflow-integer",      # add, sub, mul, div, modulus, neg, shl
        "arithmetic-overflow-floating-point" # ieee_add, ieee_sub, ieee_mul, ieee_div
    ]
}

subtype_folder_mapping = {
    "arithmetic-overflow-integer": [
        "arithmetic-overflow-on-add",
        "arithmetic-overflow-on-sub",
        "arithmetic-overflow-on-mul",
        "arithmetic-overflow-on-div",
        "arithmetic-overflow-on-modulus",
        "arithmetic-overflow-on-neg",
        "arithmetic-overflow-on-shl"
    ],
    "arithmetic-overflow-floating-point": [
        "arithmetic-overflow-on-floating-point-ieee_add",
        "arithmetic-overflow-on-floating-point-ieee_sub",
        "arithmetic-overflow-on-floating-point-ieee_mul",
        "arithmetic-overflow-on-floating-point-ieee_div"
    ]
}

cc_buckets = ["cc_1_10", "cc_11_20", "cc_21_50"]

copied_files = []

for vuln_type, subtypes in vulnerability_subtypes.items():
    for subtype in subtypes:
        for cc in cc_buckets:
            # Aggregate candidates from all mapped folders
            candidate_files = []
            if subtype in subtype_folder_mapping:
                for folder_name in subtype_folder_mapping[subtype]:
                    cc_path = BASE_DIR / folder_name / cc
                    if cc_path.exists():
                        candidate_files += list(cc_path.glob("*.c"))
            else:
                cc_path = BASE_DIR / subtype / cc
                if cc_path.exists():
                    candidate_files += list(cc_path.glob("*.c"))

            if not candidate_files:
                print(f"[warn] No files for {subtype}/{cc}")
                continue

            selected = random.sample(candidate_files, min(SAMPLES_PER_BUCKET, len(candidate_files)))
            for file_path in selected:
                rel_path = Path(vuln_type) / subtype / cc / file_path.name
                dest_path = OUTPUT_DIR / rel_path
                dest_path.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy(file_path, dest_path)
                copied_files.append(str(dest_path))

print(f"[done] Copied {len(copied_files)} sampled files to {OUTPUT_DIR}")
