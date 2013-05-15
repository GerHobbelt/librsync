/* AUTOGENERATED BY mkprototab.pl, DO NOT EDIT */

typedef struct rs_prototab_ent {
    enum rs_op_kind     kind;
    int                 immediate;
    size_t              len_1, len_2;
} rs_prototab_ent_t;

extern const rs_prototab_ent_t rs_prototab[];

enum {
              RS_OP_END =    0,
        RS_OP_LITERAL_1 =  0x1,
        RS_OP_LITERAL_2 =  0x2,
        RS_OP_LITERAL_3 =  0x3,
        RS_OP_LITERAL_4 =  0x4,
        RS_OP_LITERAL_5 =  0x5,
        RS_OP_LITERAL_6 =  0x6,
        RS_OP_LITERAL_7 =  0x7,
        RS_OP_LITERAL_8 =  0x8,
        RS_OP_LITERAL_9 =  0x9,
       RS_OP_LITERAL_10 =  0xa,
       RS_OP_LITERAL_11 =  0xb,
       RS_OP_LITERAL_12 =  0xc,
       RS_OP_LITERAL_13 =  0xd,
       RS_OP_LITERAL_14 =  0xe,
       RS_OP_LITERAL_15 =  0xf,
       RS_OP_LITERAL_16 = 0x10,
       RS_OP_LITERAL_17 = 0x11,
       RS_OP_LITERAL_18 = 0x12,
       RS_OP_LITERAL_19 = 0x13,
       RS_OP_LITERAL_20 = 0x14,
       RS_OP_LITERAL_21 = 0x15,
       RS_OP_LITERAL_22 = 0x16,
       RS_OP_LITERAL_23 = 0x17,
       RS_OP_LITERAL_24 = 0x18,
       RS_OP_LITERAL_25 = 0x19,
       RS_OP_LITERAL_26 = 0x1a,
       RS_OP_LITERAL_27 = 0x1b,
       RS_OP_LITERAL_28 = 0x1c,
       RS_OP_LITERAL_29 = 0x1d,
       RS_OP_LITERAL_30 = 0x1e,
       RS_OP_LITERAL_31 = 0x1f,
       RS_OP_LITERAL_32 = 0x20,
       RS_OP_LITERAL_33 = 0x21,
       RS_OP_LITERAL_34 = 0x22,
       RS_OP_LITERAL_35 = 0x23,
       RS_OP_LITERAL_36 = 0x24,
       RS_OP_LITERAL_37 = 0x25,
       RS_OP_LITERAL_38 = 0x26,
       RS_OP_LITERAL_39 = 0x27,
       RS_OP_LITERAL_40 = 0x28,
       RS_OP_LITERAL_41 = 0x29,
       RS_OP_LITERAL_42 = 0x2a,
       RS_OP_LITERAL_43 = 0x2b,
       RS_OP_LITERAL_44 = 0x2c,
       RS_OP_LITERAL_45 = 0x2d,
       RS_OP_LITERAL_46 = 0x2e,
       RS_OP_LITERAL_47 = 0x2f,
       RS_OP_LITERAL_48 = 0x30,
       RS_OP_LITERAL_49 = 0x31,
       RS_OP_LITERAL_50 = 0x32,
       RS_OP_LITERAL_51 = 0x33,
       RS_OP_LITERAL_52 = 0x34,
       RS_OP_LITERAL_53 = 0x35,
       RS_OP_LITERAL_54 = 0x36,
       RS_OP_LITERAL_55 = 0x37,
       RS_OP_LITERAL_56 = 0x38,
       RS_OP_LITERAL_57 = 0x39,
       RS_OP_LITERAL_58 = 0x3a,
       RS_OP_LITERAL_59 = 0x3b,
       RS_OP_LITERAL_60 = 0x3c,
       RS_OP_LITERAL_61 = 0x3d,
       RS_OP_LITERAL_62 = 0x3e,
       RS_OP_LITERAL_63 = 0x3f,
       RS_OP_LITERAL_64 = 0x40,
       RS_OP_LITERAL_N1 = 0x41,
       RS_OP_LITERAL_N2 = 0x42,
       RS_OP_LITERAL_N4 = 0x43,
       RS_OP_LITERAL_N8 = 0x44,
       RS_OP_COPY_N1_N1 = 0x45,
       RS_OP_COPY_N1_N2 = 0x46,
       RS_OP_COPY_N1_N4 = 0x47,
       RS_OP_COPY_N1_N8 = 0x48,
       RS_OP_COPY_N2_N1 = 0x49,
       RS_OP_COPY_N2_N2 = 0x4a,
       RS_OP_COPY_N2_N4 = 0x4b,
       RS_OP_COPY_N2_N8 = 0x4c,
       RS_OP_COPY_N4_N1 = 0x4d,
       RS_OP_COPY_N4_N2 = 0x4e,
       RS_OP_COPY_N4_N4 = 0x4f,
       RS_OP_COPY_N4_N8 = 0x50,
       RS_OP_COPY_N8_N1 = 0x51,
       RS_OP_COPY_N8_N2 = 0x52,
       RS_OP_COPY_N8_N4 = 0x53,
       RS_OP_COPY_N8_N8 = 0x54,
      RS_OP_RESERVED_85 = 0x55,
      RS_OP_RESERVED_86 = 0x56,
      RS_OP_RESERVED_87 = 0x57,
      RS_OP_RESERVED_88 = 0x58,
      RS_OP_RESERVED_89 = 0x59,
      RS_OP_RESERVED_90 = 0x5a,
      RS_OP_RESERVED_91 = 0x5b,
      RS_OP_RESERVED_92 = 0x5c,
      RS_OP_RESERVED_93 = 0x5d,
      RS_OP_RESERVED_94 = 0x5e,
      RS_OP_RESERVED_95 = 0x5f,
      RS_OP_RESERVED_96 = 0x60,
      RS_OP_RESERVED_97 = 0x61,
      RS_OP_RESERVED_98 = 0x62,
      RS_OP_RESERVED_99 = 0x63,
     RS_OP_RESERVED_100 = 0x64,
     RS_OP_RESERVED_101 = 0x65,
     RS_OP_RESERVED_102 = 0x66,
     RS_OP_RESERVED_103 = 0x67,
     RS_OP_RESERVED_104 = 0x68,
     RS_OP_RESERVED_105 = 0x69,
     RS_OP_RESERVED_106 = 0x6a,
     RS_OP_RESERVED_107 = 0x6b,
     RS_OP_RESERVED_108 = 0x6c,
     RS_OP_RESERVED_109 = 0x6d,
     RS_OP_RESERVED_110 = 0x6e,
     RS_OP_RESERVED_111 = 0x6f,
     RS_OP_RESERVED_112 = 0x70,
     RS_OP_RESERVED_113 = 0x71,
     RS_OP_RESERVED_114 = 0x72,
     RS_OP_RESERVED_115 = 0x73,
     RS_OP_RESERVED_116 = 0x74,
     RS_OP_RESERVED_117 = 0x75,
     RS_OP_RESERVED_118 = 0x76,
     RS_OP_RESERVED_119 = 0x77,
     RS_OP_RESERVED_120 = 0x78,
     RS_OP_RESERVED_121 = 0x79,
     RS_OP_RESERVED_122 = 0x7a,
     RS_OP_RESERVED_123 = 0x7b,
     RS_OP_RESERVED_124 = 0x7c,
     RS_OP_RESERVED_125 = 0x7d,
     RS_OP_RESERVED_126 = 0x7e,
     RS_OP_RESERVED_127 = 0x7f,
     RS_OP_RESERVED_128 = 0x80,
     RS_OP_RESERVED_129 = 0x81,
     RS_OP_RESERVED_130 = 0x82,
     RS_OP_RESERVED_131 = 0x83,
     RS_OP_RESERVED_132 = 0x84,
     RS_OP_RESERVED_133 = 0x85,
     RS_OP_RESERVED_134 = 0x86,
     RS_OP_RESERVED_135 = 0x87,
     RS_OP_RESERVED_136 = 0x88,
     RS_OP_RESERVED_137 = 0x89,
     RS_OP_RESERVED_138 = 0x8a,
     RS_OP_RESERVED_139 = 0x8b,
     RS_OP_RESERVED_140 = 0x8c,
     RS_OP_RESERVED_141 = 0x8d,
     RS_OP_RESERVED_142 = 0x8e,
     RS_OP_RESERVED_143 = 0x8f,
     RS_OP_RESERVED_144 = 0x90,
     RS_OP_RESERVED_145 = 0x91,
     RS_OP_RESERVED_146 = 0x92,
     RS_OP_RESERVED_147 = 0x93,
     RS_OP_RESERVED_148 = 0x94,
     RS_OP_RESERVED_149 = 0x95,
     RS_OP_RESERVED_150 = 0x96,
     RS_OP_RESERVED_151 = 0x97,
     RS_OP_RESERVED_152 = 0x98,
     RS_OP_RESERVED_153 = 0x99,
     RS_OP_RESERVED_154 = 0x9a,
     RS_OP_RESERVED_155 = 0x9b,
     RS_OP_RESERVED_156 = 0x9c,
     RS_OP_RESERVED_157 = 0x9d,
     RS_OP_RESERVED_158 = 0x9e,
     RS_OP_RESERVED_159 = 0x9f,
     RS_OP_RESERVED_160 = 0xa0,
     RS_OP_RESERVED_161 = 0xa1,
     RS_OP_RESERVED_162 = 0xa2,
     RS_OP_RESERVED_163 = 0xa3,
     RS_OP_RESERVED_164 = 0xa4,
     RS_OP_RESERVED_165 = 0xa5,
     RS_OP_RESERVED_166 = 0xa6,
     RS_OP_RESERVED_167 = 0xa7,
     RS_OP_RESERVED_168 = 0xa8,
     RS_OP_RESERVED_169 = 0xa9,
     RS_OP_RESERVED_170 = 0xaa,
     RS_OP_RESERVED_171 = 0xab,
     RS_OP_RESERVED_172 = 0xac,
     RS_OP_RESERVED_173 = 0xad,
     RS_OP_RESERVED_174 = 0xae,
     RS_OP_RESERVED_175 = 0xaf,
     RS_OP_RESERVED_176 = 0xb0,
     RS_OP_RESERVED_177 = 0xb1,
     RS_OP_RESERVED_178 = 0xb2,
     RS_OP_RESERVED_179 = 0xb3,
     RS_OP_RESERVED_180 = 0xb4,
     RS_OP_RESERVED_181 = 0xb5,
     RS_OP_RESERVED_182 = 0xb6,
     RS_OP_RESERVED_183 = 0xb7,
     RS_OP_RESERVED_184 = 0xb8,
     RS_OP_RESERVED_185 = 0xb9,
     RS_OP_RESERVED_186 = 0xba,
     RS_OP_RESERVED_187 = 0xbb,
     RS_OP_RESERVED_188 = 0xbc,
     RS_OP_RESERVED_189 = 0xbd,
     RS_OP_RESERVED_190 = 0xbe,
     RS_OP_RESERVED_191 = 0xbf,
     RS_OP_RESERVED_192 = 0xc0,
     RS_OP_RESERVED_193 = 0xc1,
     RS_OP_RESERVED_194 = 0xc2,
     RS_OP_RESERVED_195 = 0xc3,
     RS_OP_RESERVED_196 = 0xc4,
     RS_OP_RESERVED_197 = 0xc5,
     RS_OP_RESERVED_198 = 0xc6,
     RS_OP_RESERVED_199 = 0xc7,
     RS_OP_RESERVED_200 = 0xc8,
     RS_OP_RESERVED_201 = 0xc9,
     RS_OP_RESERVED_202 = 0xca,
     RS_OP_RESERVED_203 = 0xcb,
     RS_OP_RESERVED_204 = 0xcc,
     RS_OP_RESERVED_205 = 0xcd,
     RS_OP_RESERVED_206 = 0xce,
     RS_OP_RESERVED_207 = 0xcf,
     RS_OP_RESERVED_208 = 0xd0,
     RS_OP_RESERVED_209 = 0xd1,
     RS_OP_RESERVED_210 = 0xd2,
     RS_OP_RESERVED_211 = 0xd3,
     RS_OP_RESERVED_212 = 0xd4,
     RS_OP_RESERVED_213 = 0xd5,
     RS_OP_RESERVED_214 = 0xd6,
     RS_OP_RESERVED_215 = 0xd7,
     RS_OP_RESERVED_216 = 0xd8,
     RS_OP_RESERVED_217 = 0xd9,
     RS_OP_RESERVED_218 = 0xda,
     RS_OP_RESERVED_219 = 0xdb,
     RS_OP_RESERVED_220 = 0xdc,
     RS_OP_RESERVED_221 = 0xdd,
     RS_OP_RESERVED_222 = 0xde,
     RS_OP_RESERVED_223 = 0xdf,
     RS_OP_RESERVED_224 = 0xe0,
     RS_OP_RESERVED_225 = 0xe1,
     RS_OP_RESERVED_226 = 0xe2,
     RS_OP_RESERVED_227 = 0xe3,
     RS_OP_RESERVED_228 = 0xe4,
     RS_OP_RESERVED_229 = 0xe5,
     RS_OP_RESERVED_230 = 0xe6,
     RS_OP_RESERVED_231 = 0xe7,
     RS_OP_RESERVED_232 = 0xe8,
     RS_OP_RESERVED_233 = 0xe9,
     RS_OP_RESERVED_234 = 0xea,
     RS_OP_RESERVED_235 = 0xeb,
     RS_OP_RESERVED_236 = 0xec,
     RS_OP_RESERVED_237 = 0xed,
     RS_OP_RESERVED_238 = 0xee,
     RS_OP_RESERVED_239 = 0xef,
     RS_OP_RESERVED_240 = 0xf0,
     RS_OP_RESERVED_241 = 0xf1,
     RS_OP_RESERVED_242 = 0xf2,
     RS_OP_RESERVED_243 = 0xf3,
     RS_OP_RESERVED_244 = 0xf4,
     RS_OP_RESERVED_245 = 0xf5,
     RS_OP_RESERVED_246 = 0xf6,
     RS_OP_RESERVED_247 = 0xf7,
     RS_OP_RESERVED_248 = 0xf8,
     RS_OP_RESERVED_249 = 0xf9,
     RS_OP_RESERVED_250 = 0xfa,
     RS_OP_RESERVED_251 = 0xfb,
     RS_OP_RESERVED_252 = 0xfc,
     RS_OP_RESERVED_253 = 0xfd,
     RS_OP_RESERVED_254 = 0xfe,
     RS_OP_RESERVED_255 = 0xff};
/* END OF AUTOGENERATED CODE */
